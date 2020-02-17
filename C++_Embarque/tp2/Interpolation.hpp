// Copyright none
#pragma once

class Interpolation {
 public:
    Interpolation() {}
    ~Interpolation() {}
    virtual const double get_value(const double x) const = 0;
};
