// Copyright none
#pragma once

class Interpolation {
 public:
    Interpolation() {}
    virtual ~Interpolation() = default;
    virtual const double get_value(const double x) const = 0;
};
