#pragma once
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
#include <vector>
#include <thread>

#if defined(__GNUC__)
#define ALIGN32(X) X __attribute__((aligned(32)))
#elif defined(_MSC_VER)
#define ALIGN32(X)  __declspec(align(32)) X
#else
#error "Error: not alignment directive"
#endif

// Mother class for all decimation methods
class Decimation {
 protected:
  uint nb_threads_; // for multithread, but not used for now

 public:
  // constructor
    explicit Decimation(const uint nb_threads): nb_threads_{nb_threads} {}
  // To override by childs classes
  // do an horizontal/vertical decimation by factor 2
  // Optimized for multithreading
    virtual void horizontal(uint16_t *dst_ptr, uint16_t *src_ptr,
                           uint dst_width, uint dst_height,
                           uint dst_stride, uint src_stride,
                           uint thread = 0, uint max_thread = 1) = 0;
    virtual void vertical(uint16_t *dst_ptr, uint16_t *src_ptr,
                          uint dst_width, uint dst_height,
                          uint dst_stride, uint src_stride,
                          uint thread = 0, uint max_thread = 1) = 0;
  // Just to print the current decimation type 
    virtual std::string type() = 0;

  // multithreaded methods to do the decimation
    void do_horizontal(uint16_t *dst_ptr, uint16_t *src_ptr,
                           uint dst_width, uint dst_height,
                           uint dst_stride, uint src_stride,
                           uint max_thread = 1) {
      std::vector<std::thread> threads;

      for (uint i = 0; i < max_thread; ++i) {
        threads.emplace_back([=](){
          horizontal(
          dst_ptr, src_ptr,
          dst_width, dst_height,
          dst_stride, src_stride,
          i, max_thread);
        });
      }

      for (auto &thread_elem : threads)
        thread_elem.join();
    }
    void do_vertical(uint16_t *dst_ptr, uint16_t *src_ptr,
                    uint dst_width, uint dst_height,
                    uint dst_stride, uint src_stride,
                    uint max_thread = 1) {

      std::vector<std::thread> threads;

      for (uint i = 0; i < max_thread; ++i) {
        threads.emplace_back([=](){
          vertical(
          dst_ptr, src_ptr,
          dst_width, dst_height,
          dst_stride, src_stride,
          i, max_thread);
        });
      }

      for (auto &thread_elem : threads)
        thread_elem.join();
    }
};

// Simple decimation
// Take 1 pixel each 2 pixel from the source image
class SimpleDecimation: public Decimation{
 public:
    explicit SimpleDecimation(const uint nb_threads);

    void horizontal(uint16_t *dst_ptr, uint16_t *src_ptr,
                           uint dst_width, uint dst_height,
                           uint dst_stride, uint src_stride,
                           uint thread = 0, uint max_thread = 1) override;
    void vertical(uint16_t *dst_ptr, uint16_t *src_ptr,
                    uint dst_width, uint dst_height,
                    uint dst_stride, uint src_stride,
                    uint thread = 0, uint max_thread = 1) override;
    std::string type() override;
};

// Convolved decimation
// Take 1 pixel each 2 pixel from the source image
// but do a convolution for each pixels
class ConvolutionDecimation: public Decimation{
 private:
  // coeffs for convolution
    const int16_t coeff_[7] = {-3578, 69, 11139, 17508, 11139, 69, -3578};
  // centered so that we can use negative index
    const int16_t *fir_coeff_ = &coeff_[3];

 public:
    explicit ConvolutionDecimation(const uint nb_threads);

    void horizontal(uint16_t *dst_ptr, uint16_t *src_ptr,
                           uint dst_width, uint dst_height,
                           uint dst_stride, uint src_stride,
                           uint thread = 0, uint max_thread = 1) override;
    void vertical(uint16_t *dst_ptr, uint16_t *src_ptr,
                    uint dst_width, uint dst_height,
                    uint dst_stride, uint src_stride,
                    uint thread = 0, uint max_thread = 1) override;
    std::string type() override;
};

// Vectorized decimation
// Same method as convolved decimation
// but uses vectorized instruction to be faster
class VectorizedDecimation: public Decimation{
 private:
  // we add a 0 at the beginning to have 8 values
    const int16_t ALIGN32(coeff_[8]) = {0, -3578, 69, 11139, 17508, 11139, 69, -3578};

 public:
    explicit VectorizedDecimation(const uint nb_threads);

    void horizontal(uint16_t *dst_ptr, uint16_t *src_ptr,
                           uint dst_width, uint dst_height,
                           uint dst_stride, uint src_stride,
                           uint thread = 0, uint max_thread = 1) override;
    void vertical(uint16_t *dst_ptr, uint16_t *src_ptr,
                    uint dst_width, uint dst_height,
                    uint dst_stride, uint src_stride,
                    uint thread = 0, uint max_thread = 1) override;
    std::string type() override;
};
