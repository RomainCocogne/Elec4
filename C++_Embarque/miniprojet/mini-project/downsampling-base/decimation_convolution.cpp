// header-start
////////////////////////////////////////////////////////////////////////////////
// \file      decimation_convolution.cpp
//
// \brief     low level function for image decimation
//
// \legal     Copyright (c) 2020
//
// \author    Bernard
//
////////////////////////////////////////////////////////////////////////////////
// header-end

#include <string>
#include "./util.h"
#include "./decimation.h"

ConvolutionDecimation::ConvolutionDecimation(const uint nb_threads):
        Decimation(nb_threads) {}

std::string ConvolutionDecimation::type () { return "Convolution";}

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

void ConvolutionDecimation::horizontal(uint16_t *dst_ptr, uint16_t *src_ptr,
                           uint dst_width, uint dst_height,
                           uint dst_stride, uint src_stride,
                           uint thread, uint max_thread) {
  //

  int max_idx = 2*dst_width-1;
  uint start = thread*dst_height/max_thread;
  uint end = (thread+1)*dst_height/max_thread;

  for (uint y = start; y < end; ++y) {
    uint16_t *src_row0 = &src_ptr[y*src_stride];
    uint16_t *dst_row0 = &dst_ptr[y*dst_stride];
    int k = 0;
    for (uint x = 0; x < dst_width; ++x)  {
      k = 2*x;
      int sum = 0;
      for (int i = -3; i <= 3; ++i) {
        int idx = k + i;
        idx = (idx <= 0) ? 0 : ((idx >= max_idx) ? max_idx : idx);
        int32_t data = static_cast<int32_t>(src_row0[idx]);
        sum += data * fir_coeff_[i];
      }
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
void ConvolutionDecimation::vertical(uint16_t *dst_ptr, uint16_t *src_ptr,
                    uint dst_width, uint dst_height,
                    uint dst_stride, uint src_stride,
                           uint thread, uint max_thread) {
  //

  int max_idy = (2*dst_height-1)*src_stride;
  uint start = thread*dst_height/max_thread;
  uint end = (thread+1)*dst_height/max_thread;

  for (uint x = 0; x < dst_width; ++x) {
    uint16_t *src_col0 = &src_ptr[x];
    uint16_t *dst_col0 = &dst_ptr[x];
    int k = 0;
    for (uint y = start; y < end; ++y) {
      k = 2*y;
      int sum = 0;
      for (int i = -3; i <= 3; ++i) {
        int idy = (k + i)*dst_stride;
        idy = (idy <= 0) ? 0 : ((idy >= max_idy) ? max_idy : idy);
        int32_t data = static_cast<int32_t>(src_col0[idy]);
        sum += data * fir_coeff_[i];
      }
      sum = ((sum + (2 << 14)) >> 15);
      sum = (sum < 0) ? 0 : (sum > 1023) ? 1023 : sum;
      dst_col0[y*dst_stride] = static_cast<uint16_t>(sum);
    }
  }
}
