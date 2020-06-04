//
// header-start
//////////////////////////////////////////////////////////////////////////////////
//
// \file      util.h
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
#pragma once

#include <string>
#include <sstream>

namespace Util {

//
// Clamp class functor
//
template<typename tpl_t>
class Clamp {
private:
  int min_;
  int max_;
public:
  int operator()(tpl_t value) {
    int tmp = static_cast<int>(value);
    return (tmp < min_) ? min_ : ((tmp > max_) ? max_ : tmp);
  }
  Clamp(int min, int max) : min_{min}, max_{max} {
  }
};

//
// Commify class functor
// thousand digit separator
// 1234 => 1,234
//

class Commify {
private:
  std::string str_;
  void insert_separator(char c) {
    int pos = str_.length() - 3;
    while (pos > 0) {
      str_.insert(pos, 1, c);
      pos -= 3;
    }
  }
public:
  explicit Commify(int value) {
    std::ostringstream ss;
    ss << value;
    str_ = ss.str();
    insert_separator(',');
  }
  friend std::ostream& operator<<(std::ostream &os, const Commify &c) {
    os << c.str_;
    return os;
  }
};

}  // namespace Util
