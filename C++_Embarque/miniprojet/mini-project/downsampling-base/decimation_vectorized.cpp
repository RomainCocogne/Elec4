// header-start
////////////////////////////////////////////////////////////////////////////////
// \file      decimation_vectorized.cpp
//
// \brief     low level function for image decimation using intrinsics
//
// \legal     Copyright (c) 2020
//
// \author    Bernard
//
////////////////////////////////////////////////////////////////////////////////
// header-end


#include <tmmintrin.h>
#include <emmintrin.h>
#include <smmintrin.h>
#include <iostream>
#include <iomanip>

#include "./util.h"
#include "./decimation.h"


#if defined(__GNUC__)
#define ALIGN32(X) X __attribute__((aligned(32)))
#elif defined(_MSC_VER)
#define ALIGN32(X)  __declspec(align(32)) X
#else
#error "Error: not alignment directive"
#endif



VectorizedDecimation::VectorizedDecimation(const uint nb_threads):
        Decimation(nb_threads) {}

std::string VectorizedDecimation::type () { return "Vectorized";}

//! \brief
//!  This function performs the horizontal decimation by 2 of a
//!  source component (16 bits per pixels) into a destination.
//!
//!       source          destination
//!       2*width           width
//!     +--------------+   +------+
//!     |              |   |      |
//!     |              |   |      |
//!     +--------------+   +------+
//!
//! Filter coefficients are calculated by scilab with the following script
//! Fc = 0.249;
//! N = 7;
//! Lobe = 9;
//! Wc = 2*%pi*Fc;
//!
//! function y=my_filter(x)
//!   Cx = (Wc/%pi)*sinc(Wc*x); // Coeff based on sinc(x) = sin(x)/x
//!   Wx = sinc((%pi/Lobe)*x);  // Lanczos Window
//!   y  = Cx .* Wx;
//! endfunction
void VectorizedDecimation::horizontal(uint16_t *dst_ptr, uint16_t *src_ptr,
                           uint dst_width, uint dst_height,
                           uint dst_stride, uint src_stride,
                           uint thread, uint max_thread) {
  //
  // for multi-threading
  uint start = thread*dst_height/max_thread;
  uint end = (thread+1)*dst_height/max_thread;

  int max_idx = (2*dst_width);

  // load the coefficients
  __m128i r128_coeff = _mm_load_si128((__m128i *)coeff_);

  for (uint y = start; y < end; ++y) {
    uint16_t *src_row0 = &src_ptr[y*src_stride];
    uint16_t *dst_row0 = &dst_ptr[y*dst_stride];
    uint k = 0; // pixel index

    // takes care of limit conditions
    // first and last lines are apart
    // for the rest, we can use the 4 pixels difference
    // between width and stride to fill with correct value
    if (y > 0 && y < dst_height-1) {
      src_row0[-4] = src_row0[0];
      src_row0[-3] = src_row0[0];
      src_row0[-2] = src_row0[0];
      src_row0[-1] = src_row0[0];
      src_row0[2*dst_width+2] = src_row0[2*dst_width-1];
      src_row0[2*dst_width+1] = src_row0[2*dst_width-1];
      src_row0[2*dst_width] = src_row0[2*dst_width-1];
    }

    for (uint x = 0; x < dst_width; ++x)  {
      k = 2*x;  // do the sampling

      int32_t sum = 0;
      __m128i r128_data;

      // limit condition:
      // first and last lines and 4 first and last pixels
      // we must do a loop to get correct values
      if ((y == 0 && k < 4) || (y == dst_height-1 && k > 2*dst_width-4)) {
        for (int i = -4; i <= 3; ++i) {
          int idx = (k + i);
          idx = (idx <= 0) ? 0 : ((idx >= max_idx) ? max_idx : idx);
          uint16_t d = static_cast<int16_t>(src_row0[idx]);
          r128_data = _mm_insert_epi16(r128_data, d, i+4);
        }
      } else {
        // faster than loop
        // used for the rest of the picture
        r128_data = _mm_loadu_si128((__m128i *) (src_row0+k-4));
      }
      // convolution with intrinsinct functions
      __m128i r128_mid_sum = _mm_madd_epi16(r128_coeff, r128_data);
      r128_mid_sum = _mm_hadd_epi32(r128_mid_sum, r128_mid_sum);
      r128_mid_sum = _mm_hadd_epi32(r128_mid_sum, r128_mid_sum);
      sum = _mm_extract_epi32(r128_mid_sum, 0);

      sum = ((sum + (2 << 14)) >> 15);
      sum = (sum < 0) ? 0 : (sum > 1023) ? 1023 : sum;
      dst_row0[x] = static_cast<uint16_t>(sum);
    }
  }
}



//! \brief
//!  This function performs the vertical decimation by 2 of a source component (16 bits per pixels)
//!  into a destination.
//!
//!       source          destination
//!        width           width
//!       +------+       +------+
//!       |      |       |      |   height
//!       |      |       |      |
//!       |      |       +------+
//!       |      |
//!       |      |  2*height
//!       +------+
//!

void VectorizedDecimation::vertical(uint16_t *dst_ptr, uint16_t *src_ptr,
                    uint dst_width, uint dst_height,
                    uint dst_stride, uint src_stride,
                           uint thread, uint max_thread) {
  //

  __m128i r128_coeff = _mm_load_si128((__m128i*)coeff_);
  int max_idy = (2*dst_height-1)*src_stride;

  uint start = thread*dst_height/max_thread;
  uint end = (thread+1)*dst_height/max_thread;

  for (uint x = 0; x < dst_width; ++x) {
    uint16_t *src_col0 = &src_ptr[x];
    uint16_t *dst_col0 = &dst_ptr[x];
    int k = 0;
    for (uint y = start; y < end; ++y) {
      k = 2*y;
      int32_t sum = 0;
      __m128i r128_data;
      int16_t d[8];

      // we must do a loop to get the correct values
      for (int i = -4; i <= 3; ++i) {
        int idy = (k + i)*dst_stride;
        idy = (idy <= 0) ? 0 : ((idy >= max_idy) ? max_idy : idy);
         d[i+4] = static_cast<int16_t>(src_col0[idy]);
        // r128_data = _mm_insert_epi16(r128_data, d, i+4);
      }
        r128_data = _mm_loadu_si128((__m128i *) d);
      __m128i r128_mid_sum = _mm_madd_epi16(r128_coeff, r128_data);
      r128_mid_sum = _mm_hadd_epi32(r128_mid_sum, r128_mid_sum);
      r128_mid_sum = _mm_hadd_epi32(r128_mid_sum, r128_mid_sum);
      sum = _mm_extract_epi32(r128_mid_sum, 0);

      sum = ((sum + (2 << 14)) >> 15);
      sum = (sum < 0) ? 0 : (sum > 1023) ? 1023 : sum;
      dst_col0[y*dst_stride] = static_cast<uint16_t>(sum);
    }
  }
}
