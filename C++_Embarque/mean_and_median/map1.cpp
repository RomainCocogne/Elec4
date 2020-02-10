// Copyright 2015 ng2goodies
// header-start
//////////////////////////////////////////////////////////////////////////////////
//
// \file      histogram.cpp
//
// \brief     This file belongs to the C++ tutorial project
//
// \author    Bernard
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
// mingwin: g++ -std=c++14 -O3 -o mean_and_median mean_and_median.cpp

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
#include <map>

using std::string;
using std::vector;
using std::map;

// This simple program reads from a file a set of numbers (double format)
// computes a running mean value, computes the median after sort

// This program has several problems, can you spot them

int main(int argc, char *argv[]) {
  if (argc != 2) {
    std::cerr << "Error, need a file arg" << std::endl;
    return -1;
  }

  string file_name{argv[1]};
  map<string, double> buf;
  std::ifstream fin(file_name, std::ios::in);
  if (!fin.is_open()) {
    std::cerr << "Error, invalid name file"<< std::endl;
    return -1;
  }

  string line;
  while (std::getline(fin, line)) {
    auto key = line.substr(0, line.find(" "));
    auto d = std::stod(line.substr(line.find(" "), line.length()));
    buf[key] = d;
  }

  string qin;
  for (;;) {
    std::cout << "query> ";
    std::cin >> qin;

    if (qin == "END") break;

    if (buf.find(qin) != buf.end())
      std::cout << "value[" << qin << "]= " << buf[qin] << std::endl;
    else
      std::cout << "This ID does not exists" << std::endl;
  }

  std::cout << "Bye..." << std::endl;
}
