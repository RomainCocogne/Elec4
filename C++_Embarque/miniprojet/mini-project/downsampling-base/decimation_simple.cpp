// header-start
////////////////////////////////////////////////////////////////////////////////
// \file      decimation.cpp
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

SimpleDecimation::SimpleDecimation(const uint nb_threads):
        Decimation(nb_threads) {}

std::string SimpleDecimation::type () { return "Simple";}

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


void SimpleDecimation::horizontal(uint16_t *dst_ptr, uint16_t *src_ptr,
                           uint dst_width, uint dst_height,
                           uint dst_stride, uint src_stride,
                           uint thread, uint max_thread) {
  //
  uint start = thread*dst_height/max_thread;
  uint end = (thread+1)*dst_height/max_thread;
  for (uint y = start; y < end; ++y) {
    uint16_t *src_row = &src_ptr[y*src_stride];
    uint16_t *dst_row = &dst_ptr[y*dst_stride];
    for (uint x = 0; x < dst_width; ++x) {
      dst_row[x] = src_row[2*x];
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

void SimpleDecimation::vertical(uint16_t *dst_ptr, uint16_t *src_ptr,
                    uint dst_width, uint dst_height,
                    uint dst_stride, uint src_stride,
                    uint thread, uint max_thread) {
  //
  uint start = thread*dst_width/max_thread;
  uint end = (thread+1)*dst_width/max_thread;
  for (uint x = start; x < end; ++x) {
    uint16_t *src_col = &src_ptr[x];
    uint16_t *dst_col = &dst_ptr[x];
    for (uint y = 0; y < dst_height; ++y) {
      dst_col[y*dst_stride] = src_col[2*y*src_stride];
    }
  }
}
