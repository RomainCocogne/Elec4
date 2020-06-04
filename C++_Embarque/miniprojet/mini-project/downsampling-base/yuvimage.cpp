// header-start
////////////////////////////////////////////////////////////////////////////////
// \file      yuvimage.cpp
//
// \brief     read, write & modify a yuv image
//
// \legal     Copyright (c) 2020
//
// \author    Bernard
//
////////////////////////////////////////////////////////////////////////////////
// header-end

#include <thread>
#include <vector>
#include <string>
#include <iostream>
#include <memory>
#include <fstream>
#include <cmath>
#include "./yuvimage.h"
#include "./util.h"
#include "./decimation.h"



static const bool enable_trace = false;

//
//! \brief A YuvComponent Destructor is mandatory
//!        as we have raw storage
//!
YuvComponent::~YuvComponent() {
  if (enable_trace) {
    if (raw_storage_ == nullptr) {
      std::cout << "TRACE:: delete a null component" << std::endl;
    } else {
      std::cout << "TRACE:: delete a component" << std::endl;
    }
  }

  if (raw_storage_ != nullptr) {
    delete [] raw_storage_;
  }
}


//! \brief default constructor: null sized component
//!
YuvComponent::YuvComponent() {
  if (enable_trace) {
    std::cout << "TRACE:: allocating a default component" << std::endl;
  }
  width_ = 0;
  height_ = 0;
  stride_ = 0;
  bit_depth_ = 10;
  allocated_pixels_ = 0;
  offset_first_pixel_ = 0;
  raw_storage_ = nullptr;
  ptr_ = nullptr;
}

//
//! \brief
//! This constructor is just a memory allocator taking special care
//! of the alignment and the horizontal & vertical guard
//! we need at least 8 data as a guard
//!
//!     A------B---C--------------------D---E
//!            |   |                    |   |
//!            F---X--------------------+---+
//!            |   Y                    |   |
//!            |   |                    |   |
//!            |   |                    |   |
//!            +---+--------------------+---+
//!            |   |                    |   |
//!            +---+--------------------+---+
//!
//!   A := raw_storage memory pointer returned by the system
//!
//!   X := pointer to the top left corner of the image,
//!        aligned to 32 bytes boundary
//!   Y := pointer to the 2nd line. Delta between Y and X is the stride


YuvComponent::YuvComponent(const uint width, const uint height) {
  //
  if (enable_trace) {
    std::cout << "TRACE:: allocating a component: "
              << width << "x" << height  << std::endl;
  }
  constexpr uint guard_in_pixels = 8;

  // To understand the mask, assume first that we are dealing with bytes
  // We must ensure that the stride is a multiple of 32 bytes
  // So the 5 LSB bits must be always null.
  // We can check this  with the mask 0x1f
  // If we are using short (2 bytes), we only need to ensure
  // that the 4 LSB bits are null

  constexpr uint mask  = 0x3f >> sizeof(uint16_t);

  width_ = width;
  height_ = height;
  bit_depth_ = 10;

  stride_ = width_ + (2 * guard_in_pixels);
  if ((stride_ & mask) != 0) {
    stride_ = (stride_ | mask) + 1;
  }

  allocated_pixels_ = stride_ * (height_ + 2 * guard_in_pixels) + 32;

  raw_storage_ = new uint16_t[allocated_pixels_];         // it's A
  ptr_   = Util::addr_align32<uint16_t>(raw_storage_);    // it's B
  ptr_  += guard_in_pixels * stride_;                     // it's F
  ptr_  += 0x40 >> sizeof(uint16_t);                      // it's X

  offset_first_pixel_ = ptr_ - raw_storage_;
}


union PixBufLine {
  char      buf8[16384];
  uint8_t   pxl_u8[16384];
  uint16_t  pxl_u16[8192];
};

static  PixBufLine  line;

//! \brief
//! Standard double loop
//! iterate over each row
//!  iterate over each col
//!    read a line from stream
//!    convert into uint16, and store
//!

void YuvComponent::load_from_stream(std::ifstream &yuv_strm) {
  const uint input_bit_depth = 8;
  uint  shift = 0;
  uint  round = 0;

  if (input_bit_depth > bit_depth_) {
    shift = input_bit_depth - bit_depth_;
    round = 0x1 << (shift - 1);
  } else if (input_bit_depth < bit_depth_) {
    shift = bit_depth_ - input_bit_depth;
  }

  uint16_t *ptr_col0 = ptr_;
  uint16_t v;

  for (uint y = 0; y< height_; ++y) {
    //
    // read a line, ok for 8 bit
    // in case of 16 bits, we'll have to be extra careful on the endienness.
    //
    yuv_strm.read(line.buf8, ((input_bit_depth > 8) ? 2 : 1) * width_);

    // once read, we can either up convert or down-convert
    for (uint x = 0; x < width_; ++x) {
      if (input_bit_depth > 8) {
        v = line.pxl_u16[x];
      } else {
        v = static_cast<uint16_t>(line.pxl_u8[x]);
      }

      if (input_bit_depth > bit_depth_) {
        v = (v + round) >> shift;
      } else if (input_bit_depth < bit_depth_) {
        v <<= shift;
      }

      ptr_col0[x] = v;
    }
    ptr_col0 += stride_;
  }
}


//!  \brief write data to a file stream
//!  \param[in] outstrm           the output stream
//

void YuvComponent::write_to_stream(std::ofstream& outstrm) const {
  if (enable_trace) {
    std::cout << "TRACE:: component write to stream: "
              << width_ << "x" << height_  << std::endl;
  }
  const uint out_bit_depth = 8;

  uint round = 0;
  uint shift = 0;
  uint max = (0x1 << out_bit_depth) - 1;

  Util::Clamp<uint16_t> clamp_pixel_value(0, max);

  if (out_bit_depth < bit_depth_) {
    shift = bit_depth_ - out_bit_depth;
    round = 0x1 << (shift - 1);
  } else if (out_bit_depth > bit_depth_) {
    shift = out_bit_depth - bit_depth_;
  }

  uint16_t *ptr_col0 = ptr_;
  uint v;

  // standard double loop
  // iterate over each row
  //  iterator over each col
  //   read from stream

  for (uint y = 0; y< height_; ++y) {
    //
    // three cases: directly or upconvert
    // note that the down convert is not supported
    //
    for (uint x = 0; x < width_; ++x) {
      v = static_cast<uint>(ptr_col0[x]);
      if (out_bit_depth < bit_depth_) {
        v = (v + round) >> shift;
      } else if (out_bit_depth > bit_depth_) {
        v <<= shift;
      }

      v = clamp_pixel_value(v);

      if (out_bit_depth > 8) {
        line.pxl_u16[x] = static_cast<uint16_t>(v);
      } else {
        line.pxl_u8[x] = static_cast<uint8_t>(v);
      }
    }

    outstrm.write(line.buf8, ((out_bit_depth > 8) ? 2 : 1) * width_);
    ptr_col0 += stride_;
  }
}


//
// Copy constructor
//
YuvComponent::YuvComponent(const YuvComponent &component) {
  width_ = component.width_;
  height_ = component.height_;
  if (enable_trace) {
    std::cout << "TRACE: copy constructor for a component: "
              << width_ << "x" << height_  << std::endl;
  }
  stride_ = component.stride_;
  allocated_pixels_ = component.allocated_pixels_;
  bit_depth_ = component.bit_depth_;

  if (component.raw_storage_ != nullptr) {
    raw_storage_ = new uint16_t[allocated_pixels_];
    ptr_ = raw_storage_ + offset_first_pixel_;
  } else {
    raw_storage_ = nullptr;
    ptr_ = nullptr;
  }
}

//
//! \brief Move constructor
//! It is critical that the move constructor is marked with noexcept
//! Otherwise the compiler will default to the copy constructor
YuvComponent::YuvComponent(YuvComponent &&component) noexcept {
  width_ = component.width_;
  height_ = component.height_;
  if (enable_trace) {
    std::cout << "TRACE:: move constructor for a component: "
              << width_ << "x" << height_  << std::endl;
  }
  stride_ = component.stride_;
  allocated_pixels_ = component.allocated_pixels_;
  bit_depth_ = component.bit_depth_;
  raw_storage_ = component.raw_storage_;
  ptr_ =  component.ptr_;

  component.raw_storage_ = nullptr;
  component.ptr_ = nullptr;
}


//
//! \brief standard non threaded version
//! The downsize is done in two steps
//! 1. Horizontal
//! 2. Vertical
//!

void YuvComponent::downsize_from(const YuvComponent &src,
              std::unique_ptr<Decimation> *dec_ptr) {
  //
  //
  YuvComponent tmp(width_, src.height_);

  dec_ptr->get()->horizontal(
      tmp.ptr_, src.ptr_,
      width_, src.height_,
      tmp.stride_, src.stride_);
  dec_ptr->get()->vertical(
      ptr_, tmp.ptr_,
      width_, height_,
      stride_, tmp.stride_);
}

//! \brief Multi-Threaded version

void YuvComponent::downsize_from(const YuvComponent &src, const uint max_thread,
              std::unique_ptr<Decimation> *dec_ptr) {
  //
  //
  YuvComponent tmp(width_, src.height_);

  dec_ptr->get()->do_horizontal(
  tmp.ptr_, src.ptr_,
  width_, src.height_,
  tmp.stride_, src.stride_, max_thread);

  dec_ptr->get()->do_vertical(
  ptr_, tmp.ptr_,
  width_, height_,
  stride_, tmp.stride_, max_thread);
}

//////////////////////////////////////////////////////////////////////////////
//
// YuvImage methods
//
//////////////////////////////////////////////////////////////////////////////

//! \brief Image decimation: simply decimate all the components
//! Non threaded
//
void YuvImage::downsize_from(const YuvImage &src_image, const uint max_thread,
          std::unique_ptr<Decimation> *dec_ptr) {
  for (uint i = 0; i < components_.size(); ++i) {
    components_[i].downsize_from(src_image.components_[i],
                                 max_thread, (dec_ptr));
  }
}


//! \brief
//! Threaded version: 3 thread one per component
//!
void YuvImage::downsize_threaded_by_component(const YuvImage &src_image,
          std::unique_ptr<Decimation> *dec_ptr) {
  std::thread t_y([&]() {
    components_[0].downsize_from(src_image.components_[0], (dec_ptr));
  });
  std::thread t_u([&]() {
    components_[1].downsize_from(src_image.components_[1], (dec_ptr));
  });

  components_[2].downsize_from(src_image.components_[2], (dec_ptr));

  t_u.join();
  t_y.join();
}


//! \brief Image creation for an input stream
//! we simply call component initialization from stream
//
void YuvImage::load_from_stream(std::ifstream &yuv_strm) {
  for (auto &component : components_) {
    component.load_from_stream(yuv_strm);
  }
}

void YuvImage::write(const std::string &file_name) {
  std::ofstream yuv_strm(file_name, std::ios::out | std::ios::binary | std::ios::trunc);
  yuv_strm.exceptions(std::ofstream::eofbit | std::ofstream::failbit | std::ofstream::badbit);

  for (auto &component : components_) {
    component.write_to_stream(yuv_strm);
  }
}

//! \brief
//! Constructor for the YuvImage
//! We verify that the size of the yuv file is correct

YuvImage::YuvImage(const std::string &file_name,
                   const uint width, const uint height) {
  // note the try / catch block
  try {
    std::ifstream yuv_strm(file_name, std::ios::in | std::ios::binary);
    yuv_strm.exceptions(std::ifstream::eofbit | std::ifstream::failbit | std::ifstream::badbit);

    // position stream pointer at the end to read the file size...
    yuv_strm.seekg(0, std::ios::end);
    auto filesize =  yuv_strm.tellg();

    // .. and don't forget to put it back to the beg so that we can read
    yuv_strm.seekg(0, std::ios::beg);

    auto ysize = (filesize * 2) / 3;
    if (((ysize * 3) / 2) != filesize) {
      throw wrong_size_();
    }

    if (width == 0 && height == 0) {
      // derive width and height from file size
      switch (ysize) {
        case 3840*2160: width_ = 3840; height_ = 2160; break;
        case 1920*1080: width_ = 1920; height_ = 1080; break;
        case 1024* 768: width_ = 1024; height_ =  768; break;
        case  960* 540: width_ =  960; height_ =  540; break;
        case  832* 480: width_ =  832; height_ =  480; break;
        case  512* 384: width_ =  512; height_ =  384; break;
        case  416* 240: width_ =  416; height_ =  240; break;
        case  352* 288: width_ =  352; height_ =  288; break;
        case  176* 144: width_ =  176; height_ =  144; break;
        default: throw wrong_size_();
      }
    } else {
      width_ = width;
      height_ = height;
      if ((width_ * height) != ysize) {
        throw wrong_size_();
      }
    }

    components_.reserve(3);
    components_.emplace_back(width_, height_);  // luma
    components_.emplace_back(width_ >> 1, height_ >> 1);  // cb
    components_.emplace_back(width_ >> 1, height_ >> 1);  // cr

    for (auto &component : components_) {
      component.load_from_stream(yuv_strm);
    }
  }

  catch(const std::ios_base::failure &error) {
    std::cerr << "INFO: catch i/o failure " << error.what();
    std::abort();
  }

  catch (const std::bad_alloc &error) {
    std::cerr << "INFO: catch bad_alloc " << error.what();
    std::abort();
  }

  catch(const std::exception &error) {
    std::cerr << "INFO: catch an error " << error.what();
    std::abort();
  }
}

//
//! \brief
//! Simple constructor to initialize storage from
//! given width and height
//

YuvImage::YuvImage(const uint width, const uint height) {
  width_ = width;
  height_ = height;

  components_.reserve(3);
  components_.emplace_back(width_, height_);            // luma
  components_.emplace_back(width_ >> 1, height_ >> 1);  // cb
  components_.emplace_back(width_ >> 1, height_ >> 1);  // cr
}
