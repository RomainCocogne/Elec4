// Copyright none
#pragma once
#include <vector>
#include <algorithm>
#include <iostream>
#include <iostream>
#include "Interpolation.hpp"

class Linear: public Interpolation {
 private:
    std::vector<double> x_;
    std::vector<double> a_;
    std::vector<double> b_;

 public:
    Linear(const std::vector<double> &xs, 
           const std::vector<double> &ys): 
           x_(xs) {
        for (unsigned int i = 0; i < x_.size()-2; ++i) {
            a_.push_back((ys[i+1] - ys[i]) / (x_[i+1] - x_[i]));
            b_.push_back(ys[i]);
        }
        a_.push_back(ys[0] - ys.back() / (1 - x_.back()));
        b_.push_back(ys.back());
    }
    ~Linear() {}
    const double get_value(const double x) const override {
        auto i = x_.size()-1;
        while (i > 0  && x < x_[i]) --i;
        return a_[i] * (x - x_[i]) + b_[i];
    }
};

/*
// Copyright none
#pragma once
#include <vector>
#include <algorithm>
#include <iostream>
#include "Interpolation.hpp"

class Linear: public Interpolation {
 private:
    std::vector<double> x_;
    std::vector<double> y_;

 public:
    Linear(std::vector<double> xs, std::vector<double> ys): x_(xs), y_(ys) {}
    ~Linear() {}
    const double get_value(const double x) const override {
        auto x_iterator = std::find_if(x_.begin(), x_.end(),
                              [x] (double v) -> bool {return v > x;});
        auto yi = 0.0;
        auto yip1 = 0.0;
        auto xi = 0.0;
        auto xip1 = 0.0;

        if (x_iterator != x_.end()) {
            auto rank = x_iterator-x_.begin();
            xip1 = *x_iterator;
            xi = *(x_iterator-1);
            yip1 = *(y_.begin()+rank);
            yi = *(y_.begin()+rank-1);
        } else {
            xip1 = 1;
            xi = *(x_iterator-1);
            yip1 = *y_.begin();
            yi = *(y_.end()-1);
        }
        auto b = yi;
        auto a = (yip1 - yi) / (xip1 - xi);
        return a * (x - xi) + b;
    }
};
*/
