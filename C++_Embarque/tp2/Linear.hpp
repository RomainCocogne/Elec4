// Copyright none
#pragma once
#include <vector>
#include <algorithm>
#include <iostream>
#include "Interpolation.hpp"

class Linear: public Interpolation {
 private:
    std::vector<double> x_;
    std::vector<double> a_;
    std::vector<double> b_;

 public:
    Linear(const std::vector<double> &xs,
           const std::vector<double> &ys): x_(xs) {
        for (unsigned int i = 0; i < x_.size()-1; ++i) {
            a_.push_back((ys[i+1] - ys[i]) / (x_[i+1] - x_[i]));
            b_.push_back(ys[i]);
        }
        a_.push_back((ys.front() - ys.back()) / (1 - x_.back()));
        b_.push_back(ys.back());
    }
    const double get_value(const double x) const override {
        auto i = x_.size()-1;
        while (i > 0  && x < x_[i]) --i;
        return a_[i] * (x - x_[i]) + b_[i];
    }
};
