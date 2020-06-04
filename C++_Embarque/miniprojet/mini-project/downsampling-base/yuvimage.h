// header-start
////////////////////////////////////////////////////////////////////////////////
// \file      yuvimage.h
//
// \brief     class declaration for yuv image and yuv component
//
// \legal     Copyright (c) 2020
//
// \author    Bernard
//
////////////////////////////////////////////////////////////////////////////////
// header-end

#pragma once

#include <iostream>
#include <vector>
#include <string>
#include <memory>
#include "./util.h"
#include "decimation.h"


class YuvComponent {
 private:
  uint width_;
  uint height_;
  uint stride_;
  uint bit_depth_;
  uint allocated_pixels_;
  uint offset_first_pixel_;

  uint16_t  *raw_storage_;
  uint16_t  *ptr_;



 public:
  YuvComponent();
  explicit YuvComponent(const uint width, const uint height);
  ~YuvComponent();

  // Copy constructor
  YuvComponent(const YuvComponent &component);

  // Move constructor
  YuvComponent(YuvComponent &&component) noexcept;

  void load_from_stream(std::ifstream &yuv_strm);
  void write_to_stream(std::ofstream& outstrm) const;
  void downsize_from(const YuvComponent &src,
                     std::unique_ptr<Decimation> *dec_ptr);
  void downsize_from(const YuvComponent &src, const uint max_thread,
                     std::unique_ptr<Decimation> *dec_ptr);
};


class YuvImage {
 public:
  explicit YuvImage(const std::string &file_name,
                    const uint width = 0, const uint height = 0);
  explicit YuvImage(const uint width, const uint height);
  YuvImage(const YuvImage &image);
  ~YuvImage() = default;
  void downsize_from(const YuvImage &src_image, const uint max_thread,
                     std::unique_ptr<Decimation> *dec_ptr);
  void downsize_threaded_by_component(const YuvImage &src_image,
                     std::unique_ptr<Decimation> *dec_ptr);
  void write(const std::string &file_name);

  uint width() const { return width_; }
  uint height() const { return height_; }

 private:
  void load_from_stream(std::ifstream &yuv_strm);

  // A nested class extending the exception class
  // we shall thow an exception if the size of the
  // file does not match some expected values
  // the usage is:  throw wrong_size();
  // which calls the constructor for this class
  // As you can see, no constructor exists so
  // wrong_size() calls the default constructor
  // which call the base class constructor std::exception();
  // which trigger the throw
  // the virtual function what() return a pointer to a const char *
  // the qualifers after the what() are
  // const   => this function does not change the class member value
  // noexcept => this function does not throw
  // override => this function is virtual and override the base class function

  class wrong_size_ : public std::exception {
   public:
    const char *what() const noexcept override {
      return "File has wrong size";
    }
  };

 private:
  std::vector<YuvComponent>  components_;
  int width_;
  int height_;
};
