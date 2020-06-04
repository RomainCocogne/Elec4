// header-start
////////////////////////////////////////////////////////////////////////////////
// \file      main.cpp
//
// \brief     yuv image decimation
//
// \author    Bernard
//
// \legal     Copyright 2020
//
////////////////////////////////////////////////////////////////////////////////
// header-end
//
//

#include <string>
#include <iostream>
#include <iomanip>
#include <algorithm>
#include <memory>
#include <chrono>
#include "./yuvimage.h"
#include "./decimation.h"


///////////////////////////////////////////////////////////////////////////////
//
//! \brief
//! The class TopConfig is a "standard" way of dealing with console based
//! option: it perform all the options processing and checking
//! and call the TopConfig::main() method


class TopConfig {
 public:
  TopConfig(const int argc, const char *const argv[]);
  void print_help() const;
  void print_copyright() const;
  void main();

 private:
  bool is_integer(const std::string& s) const;
  void build_decimation_type(const std::string& dec_type, uint max_thread);

  uint width_;
  uint height_;
  uint percent_;
  uint max_thread_;
  std::string file_name_;
  std::string output_file_name_;
  std::string program_name_;
  std::string program_version_;
  std::unique_ptr<Decimation> dec_ptr_;
};

//
//! \brief  entry point
//!  1. create an image from the given file
//!  2. create an empty result image, width and height are divided by two
//!  3. start a timer
//!  4. perform 10 times the image downsize
//!  5. stop the time
//!  6. report time
//!  7. dump result image in a file
//
void TopConfig::main() {
  std::cout << "Info: loading image from " << file_name_ << std::endl;

  YuvImage input_image(file_name_, width_, height_);
  std::cout << "Info: initial image size   : "
            << input_image.width() << "x" << input_image.height() << std::endl;

  YuvImage result_image(input_image.width() >> 1, input_image.height() >> 1);
  std::cout << "Info: downsized image size : "
            << result_image.width() << "x" << result_image.height() << std::endl;

  //  measure the time and start downsizing loop
  auto time_start = std::chrono::high_resolution_clock::now();
  for (int i = 0; i < 10; ++i) {
    result_image.downsize_from(input_image, max_thread_, (&dec_ptr_));
  }

  auto time_end = std::chrono::high_resolution_clock::now();
  auto elapsed_time_ms =
    std::chrono::duration_cast<std::chrono::milliseconds>
        (time_end - time_start);

  std::cout << "Info: downsized image calculated in "
            << Util::Commify(elapsed_time_ms.count()) << "ms, using "
            << max_thread_ << " thread(s)"
            << " with " << dec_ptr_.get()->type() << " decimation"
            << std::endl;

  // dump output file
  result_image.write(output_file_name_);
  std::cout << "Info: downsized image stored in file "
            << output_file_name_ << std::endl;
}


//! \brief
//! Needed in all "professional environment"

void TopConfig::print_copyright() const {
  //                     1         2         3         4         5
  //            1234567890123456789012345678901234567890123456789012345
  std::cout << "#######################################################" << std::endl;
  std::cout << "##        YUV Image Decimation  version: "
            << std::left << std::setw(6) << program_version_  << "      ##" << std::endl;
  std::cout << "#######################################################" << std::endl;
}

//! \brief
//! Standard Linux console help with usage and options
//! We use the CSI class
//! See https://en.wikipedia.org/wiki/ANSI_escape_code#CSI_codes


void TopConfig::print_help() const {
  using CSI = Util::CSI;
  std::cout << std::endl;
  std::cout << "Usage: " << program_name_ << " [options] filename" << std::endl;
  std::cout << "Options:" << std::endl;
  std::cout << "-h | --help         Display this help" << std::endl;
  std::cout << "--width " << CSI("italic") << "integer" << CSI("normal") << "    Width of the image in pixel (default: auto)" << std::endl;
  std::cout << "--height " << CSI("italic") << "integer" << CSI("normal") << "   Height of the image in pixel (default: auto)" << std::endl;
  std::cout << "--percent " << CSI("italic") << "integer" << CSI("normal") << "  Resize percentage between 10 to 100 (default: 50)" << std::endl;
  std::cout << "--output " << CSI("italic") << "filename" << CSI("normal") << "  Name of the output file (default: downsize.yuv)" << std::endl;
  std::cout << "--threads " << CSI("italic") << "integer" << CSI("normal") << "  Number of threads (default: 1)" << std::endl;
  std::cout << "--method " << CSI("italic") << "string" << CSI("normal") << "  Choices: simple, convolution or vectorized (default: simple)" << std::endl;
}

//
// Ugly macros, but a fail safe in case
// the program version is not provided by a -D
// compiler option
//

//
//! \brief 
//! This simple method uses the all_of() STL algorithm
//! and a lambda function calling the isdigit function to ensure that the given
//! string is only composed of digit characters range 0 to 9
//! We could also have done it without the lambda function but it is less clear
//! solution 1: return std::all_of(s.begin(), s.end(), ::isdigit);
//! solution 2: return s.find_first_not_of("0123456789") == std::string::npos;
//!
//
bool TopConfig::is_integer(const std::string& s) const {
  if (s.empty()) {
    return false;
  }
  return std::all_of(s.begin(),
                     s.end(),
                     [](char elem) -> bool { return std::isdigit(elem); });
}

//
//! \brief
//! Construct Decimation object
//! method of decimation depends of dec_type
//
void
TopConfig::build_decimation_type(const std::string& dec_type, uint max_thread) {
  if (dec_type == "convolution") {
    dec_ptr_ = std::make_unique<ConvolutionDecimation>(max_thread);
  } else if (dec_type == "vectorized") {
    dec_ptr_ =  std::make_unique<VectorizedDecimation>(max_thread);
  } else if (dec_type == "simple") {
    dec_ptr_ = std::make_unique<SimpleDecimation>(max_thread);
  } else {
    std::cerr << "Bad method name" << std::endl;
    std::exit(-1);
  }
}

//
//! \brief
//! Class constructor. We have placed the const everywhere we could
//! as an example of "const correctness"
//
TopConfig::TopConfig(const int argc, const char *const argv[]) {
  // default parameters
  width_ = 0;
  height_ = 0;
  percent_ = 50;
  max_thread_ = 1;
  program_name_ = "downsampling";
  program_version_ = PROG_VERSION;
  output_file_name_ =  "downsize.yuv";
  std::string dec_type = "simple";

  file_name_ = "";

  print_copyright();

  if (argc > 1) {
    int idx = 1;
    do {
      std::string current_arg = argv[idx];
      if (current_arg == "-h" || current_arg == "--help") {
        print_help();
        std::exit(-1);

      } else if ((current_arg == "--width") ||
                 (current_arg == "--height") ||
                 (current_arg == "--threads") ||
                 (current_arg == "--percent")) {
        idx++;
        if (idx >= argc) {
          std::cerr << "Error: argument "
                    << current_arg << " needs a parameter" << std::endl;
          exit(-1);
        }
        std::string integer_arg(argv[idx]);
        if (!is_integer(integer_arg)) {
          std::cerr << "Error: argument "
                    << integer_arg << " is not an integer" << std::endl;
          exit(-1);
        }
        uint value = std::stoi(integer_arg);
        if (current_arg == "--width") {
          width_ = value;
        } else if (current_arg == "--height") {
          height_ = value;
        } else if (current_arg == "--threads") {
          max_thread_ = value;
        } else {
          percent_ = value;
        }
      } else if (current_arg == "--method") {
        ++idx;
        if (idx >= argc) {
          std::cerr << "Error: argument "
                    << current_arg << " needs a parameter" << std::endl;
          exit(-1);
        }
        dec_type = argv[idx];
      } else if (current_arg == "--output") {
        output_file_name_ = current_arg;
      } else if (file_name_ != "") {
         std::cerr << "Error: argument "
                   << current_arg << " is not valid" << std::endl;
         exit(-1);
      } else {
         file_name_ = current_arg;
      }
      idx++;
    } while (idx < argc);
  }

  build_decimation_type(dec_type, max_thread_);
  // verification that the parameters are ok
}


//! \brief
//! Standard main with TopConfig
//!

int main(int argc, char *argv[]) {
  TopConfig top_config(argc, argv);

  top_config.main();
  return 0;
}
