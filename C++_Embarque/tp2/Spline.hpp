// Copyright none
#pragma once
#include <eigen/Eigen/Dense>

class Spline {
 public:
    Spline() {}
    ~Spline() {}

    const double get_value(const double x) const override {
        return 0.0;
    }
};
