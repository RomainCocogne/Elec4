// Copyright 2015 ng2goodies
// header-start
//////////////////////////////////////////////////////////////////////////////////
//
// \file      map1.cpp
//
// \brief     This file belongs to the C++ tutorial project
//
// \author    Bernard, Romain and Philipe
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
#include <sstream>

using std::string;
using std::vector;
using std::map;

// Reads files shaped like [key   double_value] for each line
// and gives a prompt for user to enter a key.
// the corresponding value is returned

// Somme Macros to ease reading
#define PROMPT "query> "
#define EXIT_KEY "END"

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

  map<string, double> buf;  // Buffer containing file data
  string key;
  double d;
  while (fin >> key >> d)  // Reading file...
    buf[key] = d;

  string qin;
  for (;;) {  // Enter prompt loop
    std::cout << PROMPT;
    std::cin >> qin;  // Get user key

    if (qin == EXIT_KEY) break;

    if (buf.find(qin) != buf.end())  // check if key exists
      std::cout << "value[" << qin << "]= " << buf[qin] << std::endl;
    else
      std::cout << "This ID does not exists" << std::endl;
  }

  std::cout << "Bye..." << std::endl;
}
