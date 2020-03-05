// Copyright none
// header-start
//////////////////////////////////////////////////////////////////////////////////
//
// \file      random_gene.cpp
//
// \brief     This file belongs to the C++ tutorial project
//
// \author    Romain and Philipe
//
//
//////////////////////////////////////////////////////////////////////////////////
// header-end
//


// C++ version
// Compilation with g++ 5.3.0 & g++ 6.3.0
// mingwin: g++ -std=c++14 -O3 -o random_gene random_gene.cpp

// Compilation with g++ 4.9.3
// cygwin:  g++ -D_GLIBCXX_USE_C99 -D_GLIBCXX_USE_C99_DYNAMIC -std=c++14 -O3 ...

// Other tool chain
// msvc:    ok!
// clang:   ok!

#include <fstream>
#include <iostream>
#include <random>

using std::string;

// Generate a n random values following a logarithmic normal distribution
// and save them in a file

int main(int argc, char const *argv[]) {
  // Check numer of args
  if (argc != 3) {
    std::cerr << "Error, arguments must be \'number_of_double file_name\'"
    << std::endl;
    return -1;
  }
  // Try to get n
  int n;
  try {
    n = std::stoi(argv[1]);
  } catch (...) {
    std::cerr << "Error in first argument" << std::endl;
    return -1;
  }

  // Create the file
  string file_name{argv[2]};
  std::ofstream fou(file_name, std::ofstream::out);

  // Generate normal distribution
  std::random_device rd{};
  std::minstd_rand gen{rd()};
  std::lognormal_distribution<double> distribution(7.6, 0.45);

  // Generate and write random numbers
  double number;
  for (int i = 0; i < n; i++) {
    number = distribution(gen);
    fou << number<< std::endl;
  }

  return 0;
}
