// Copyright 2015 ng2goodies
// header-start
//////////////////////////////////////////////////////////////////////////////////
//
// \file      histogram.cpp
//
// \brief     This file belongs to the C++ tutorial project
//
// \authors    Bernard, Romain and Philipe
//
// \copyright Copyright [2015] <ng2goodies>
//            Distributed under the MIT License
//            See http://opensource.org/licenses/MIT
//
//////////////////////////////////////////////////////////////////////////////////
// header-end
//


// C++ version
// Compilation with g++ 5.3.0 & g++ 6.3.0
// mingwin: g++ -std=c++14 -O3 -o histogram histogram.cpp

// Compilation with g++ 4.9.3
// cygwin:  g++ -D_GLIBCXX_USE_C99 -D_GLIBCXX_USE_C99_DYNAMIC -std=c++14 -O3 ...

// Other tool chain
// msvc:    ok!
// clang:   ok!


#include <string>
#include <vector>
#include <fstream>
#include <iostream>
#include <algorithm>
#include <iomanip>

using std::string;
using std::vector;

// This simple program reads from a file a set of numbers (double format)
// computes a running mean value, computes the median after sort.
// Gives a graphical overview of values density into set intervals

// Somme Macros to ease reading
#define STEP_SIZE 100
#define I_MAX 8000
#define STAR_MAX 60


int main(int argc, char *argv[]) {
  // Check if file name is given
  if (argc != 2) {
    std::cerr << "Error, need a file arg" << std::endl;
    return -1;
  }

  // Try to open file
  string file_name{argv[1]};
  std::ifstream fin(file_name, std::ios::in);
  if (!fin.is_open()) {
    std::cerr << "Error, invalid name file"<< std::endl;
    return -1;
  }

  vector<double> buf;  // Buffer for double values
  string line;  // To read the file line by line

  auto mean = 0.0;
  auto d = 0.0;  // Get the line value

  while (std::getline(fin, line)) {  // Reading...
    try {
      d = std::stod(line);  // Converting line to double
      buf.push_back(d);  // Store value
      mean = (buf.size() == 1) ? d : mean + (d - mean) / buf.size();
    } catch (...) {  // If double converting fails
      std::cerr << "Error, wrong values in file" << std::endl;
      return -1;
    }
  }

  std::sort(buf.begin(), buf.end());

  auto mid = buf.size() / 2;
  double median = (buf.size() % 2) ? buf[mid] :
                                     (buf[mid - 1] + buf[mid]) / 2;

  std::cout << "number of elements = " << buf.size()
            << ", median = " << median
            << ", mean = " << mean << std::endl;


  vector<double> val_in_bin;  // Store number of values inside the bin intervals

  auto b = buf.begin();
  auto n = 0;
// for each intervals
  for (int i = 0; i <I_MAX ; i+=STEP_SIZE) {
    // Count the number of values in interval
    while (*b < i+STEP_SIZE && b != buf.end()) {n++; b++;}
    // Store the value
    val_in_bin.push_back(n);
    n = 0;
  }

  // Number of stars coefficient
  auto c = STAR_MAX/(*max_element(val_in_bin.begin(), val_in_bin.end()));

  for (unsigned int j = 0; j < val_in_bin.size(); j++) {  // Print histogram
    std::cout << std::setw(4) << j*100 << std::setw(6)
              << val_in_bin[j] << " " << string(c*val_in_bin[j], '*')
              << std::endl;
  }
}
