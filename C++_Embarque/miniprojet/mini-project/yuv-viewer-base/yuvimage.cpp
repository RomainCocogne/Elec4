//
// header-start
//////////////////////////////////////////////////////////////////////////////////
//
// \file      yuvimage.cpp
//
// \brief     This file belongs to the C++ tutorial project
//
// \author    Bernard
//
// \copyright Copyright 2020
//
//////////////////////////////////////////////////////////////////////////////////
// header-end
//
#include "yuvimage.h"
#include <QString>
#include <QDebug>
#include <cmath>
#include <string>
#include <iostream>
#include <fstream>
#include "util.h"




// Convert a single yuv point to rgb color
// based on BT.709 formula
// Y = 0.2126*R + 0.7152*G + 0.0722*B
//
static
QRgb convert_yuv_to_rgb(uint8_t y, uint8_t u, uint8_t v) {
  auto yi = static_cast<int>(static_cast<uint>(y));
  auto ui = static_cast<int>(static_cast<uint>(u));
  auto vi = static_cast<int>(static_cast<uint>(v));

  Util::Clamp<int> clamp_to_rgb(0, 255);

  // BT.601
  //  r = ((298 * yi)              + (427 * vi) - 61650 + 128)  >> 8;
  //  g = ((298 * yi) - (100 * ui) - (218 * vi) + 37041 + 128)  >> 8;
  //  b = ((298 * yi) + (516 * ui)              - 70870 + 128)  >> 8;

  // BT.709
  int r = ((298 * yi)              + (480 * vi) - 68660 + 128)  >> 8;
  int g = ((298 * yi) - ( 54 * ui) - (143 * vi) + 21211 + 128)  >> 8;
  int b = ((298 * yi) + (541 * ui)              - 73988 + 128)  >> 8;

  return qRgb( clamp_to_rgb(r), clamp_to_rgb(g), clamp_to_rgb(b));
}

// Convert raw yuv data to rgb image
// process image pixel by pixel
// calling the conversion yuv to rgb each time
// The raw yuv data is in 4:2:0 format
// i.e a single chroma value (u or v) is applicable to 4 luma values.
// We haven't implemented the filtering for upscaling described in
// https://msdn.microsoft.com/en-us/library/windows/desktop/dd206750(v=vs.85).aspx
//
void YuvImage::yuv_to_rgb() {
  uint8_t *y_ptr = y_raw_;
  uint8_t *u_ptr = u_raw_;
  uint8_t *v_ptr = v_raw_;

  int uv_stride = width_ >> 1;

  for (int y = 0; y < height_; ++y) {
    uint8_t *u_ptr_row = u_ptr;
    uint8_t *v_ptr_row = v_ptr;
    for (int x = 0; x < width_; ++x) {
      uint8_t y_data  = *y_ptr;
      uint8_t u_data  = *u_ptr_row;
      uint8_t v_data  = *v_ptr_row;

      // for better performance
      // use of scanline is recommanded

      setPixel(x, y, convert_yuv_to_rgb(y_data, u_data, v_data));

      // need to increment the pointers
      // luma pointer: always
      // chroma pointer: on odd pixels
      y_ptr++;
      if (x & 0x1) {
        u_ptr_row++;
        v_ptr_row++;
      }
    }
    // only increment the uv pointers
    // at the end of odd rows;
    if (y & 0x1) {
      u_ptr += uv_stride;
      v_ptr += uv_stride;
    }
  }
}

// Assist function for YUV to RGB image creation
// allocate the memory buffers
// and read raw yuv from the ifstream into the buffers
//
void YuvImage::load_from_stream(std::ifstream &yuv_strm) {
  auto y_size = width_ * height_;
  auto uv_size =  y_size >> 2;

  // we have a catch bad_alloc in the caller
  y_raw_ = new uint8_t [y_size];
  u_raw_ = new uint8_t [uv_size];
  v_raw_ = new uint8_t [uv_size];

  // we have a catch ios::failure in the caller
  yuv_strm.read(reinterpret_cast<char *>(y_raw_), y_size);
  yuv_strm.read(reinterpret_cast<char *>(u_raw_), uv_size);
  yuv_strm.read(reinterpret_cast<char *>(v_raw_), uv_size);
}

//! \brief
//! Constructor for the YuvImage
//! Note that the default QImage
//! will not be used except if a throw.
//! We shall use QImage::swap at the end
//
static const bool yuv_trace = false;

YuvImage::YuvImage(const std::string &file_name) :
  QImage(300, 100, QImage::Format_RGB32) {
  //
  // we find the width and height of the file
  // based on the size of the file

  y_raw_ = nullptr;
  u_raw_ = nullptr;
  v_raw_ = nullptr;
  width_ = 300;
  height_ = 100;

  try {
    std::ifstream yuv_strm(file_name, std::ios::in | std::ios::binary);
    yuv_strm.exceptions(std::ifstream::eofbit |
                        std::ifstream::failbit |
                        std::ifstream::badbit);

    // position stream pointer at the end to read the file size...
    yuv_strm.seekg(0, std::ios::end);
    auto filesize =  yuv_strm.tellg();

    // .. and don't forget to put it back to the beg so that we can read
    yuv_strm.seekg(0, std::ios::beg);

    if (yuv_trace) {
      // here we use the ostringstream to build a std::string
      // which can be displayed by qDebug()
      // yes, it is painful !
      std::ostringstream ss;
      ss << "INFO: input file " << file_name << " has " << filesize << " bytes";
      qDebug() << QString::fromStdString(ss.str());
    }

    auto ysize = (filesize * 2) / 3;
    if (((ysize * 3) / 2) != filesize) {
      throw wrong_size_();
    }

    // dumb algorithm for width and height
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
    if (yuv_trace) {
      // here we just call qDebug directly
      qDebug() << "INFO: Image width  is " << width_;
      qDebug() << "INFO: Image height is " << height_;
    }
    // ok, now width and height are known
    // we can start loading the yuv file into the raw
    // pointers
    load_from_stream(yuv_strm);

    // from now on, no more exception
    // so we can swap the images
    QImage main_image(width_, height_, QImage::Format_RGB32);
    swap(main_image);

    // ... and convert yuv raw data to rgb
    yuv_to_rgb();
  }

  catch(const std::ios_base::failure &error) {
    qDebug() << "INFO: catch i/o failure " << QString::fromStdString(error.what());
    QPainter painter(this);
    painter.fillRect(rect(), Qt::black);
    painter.setPen(Qt::white);
    painter.drawText(rect(), Qt::AlignCenter, "Could not read from file");
  }

  catch (const std::bad_alloc &error) {
    qDebug() << "INFO: catch bad_alloc " << QString::fromStdString(error.what());
    QPainter painter(this);
    painter.fillRect(rect(), Qt::black);
    painter.setPen(Qt::white);
    painter.drawText(rect(), Qt::AlignCenter, "Can't allocate memory");
  }

  catch(const std::exception &error) {
    qDebug() << "INFO: catch some error " << QString::fromStdString(error.what());
    QPainter painter(this);
    painter.fillRect(rect(), Qt::black);
    painter.setPen(Qt::white);
    painter.drawText(rect(), Qt::AlignCenter, "Incorrect file size");
  }
}

//
// Copy constructor
//
YuvImage::YuvImage(const YuvImage &image) : QImage(image) {
  width_ = image.width_;
  height_ = image.height_;
  size_t y_size = width_ * height_;
  auto uv_size =  y_size >> 2;

  if (image.y_raw_ != nullptr) {
    y_raw_ = new uint8_t [y_size];
    std::memcpy(y_raw_, image.y_raw_, y_size);
  } else {
    y_raw_ = nullptr;
  }

  if (image.u_raw_ != nullptr) {
    u_raw_ = new uint8_t [uv_size];
    std::memcpy(u_raw_, image.u_raw_, uv_size);
  } else {
    u_raw_ = nullptr;
  }

  if (image.v_raw_ != nullptr) {
    v_raw_ = new uint8_t [uv_size];
    std::memcpy(v_raw_, image.v_raw_, uv_size);
  } else {
    v_raw_ = nullptr;
  }
}

