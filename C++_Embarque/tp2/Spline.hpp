// Copyright none
#pragma once
#include <eigen/Eigen/Dense>
#include <vector>
#include <ostream>
#include <cmath>
#include "Interpolation.hpp"

class Spline: public Interpolation {
 private:
    std::vector<double> x_;
    std::vector<double> a_;
    std::vector<double> b_;
    std::vector<double> c_;
    std::vector<double> d_;
    size_t dim;

 public:
    Spline(const std::vector<double> &xs,
           const std::vector<double> &ys):
           x_(xs), d_(ys) {
        Eigen::MatrixXd m_(4*(xs.size()-1), 4*(xs.size()-1));
        Eigen::VectorXd v_(4*(xs.size()-1));
        m_.setZero();
        v_.setZero();
        auto r = 1;
        auto rd = 2*(xs.size()-1);
        auto rdd = 2*(xs.size()-1)+3;
        auto c = 0;
        m_.block(0, 0, 1, 4) << 0, 0, 0, 1;
        for (auto x : xs) {
            if (x != xs.front()) {
                m_.block(r, c, 1, 4) << pow(x, 3), pow(x, 2), x, 1;
                if (x != xs.back()){
                    m_.block(r+1, c+4, 1, 4) << pow(x, 3), pow(x, 2), x, 1;

                    m_.block(rd, c, 1, 8) << 3*pow(x, 2), 2*x, 1, 0,
                                            -3*pow(x, 2), -2*x, -1, 0;
                    m_.block(rdd, c, 1, 8) << 6*x, 2, 0, 0,
                                             -6*x, -2, 0, 0;
                }
                r += 2;
                c += 4;
                rd += 1;
                rdd += 1;
            }
        }
        std::cout << m_ << std::endl;
    }
    ~Spline() {}

    const double get_value(const double x) const override {
        auto x_iterator = std::find_if(x_.begin(), x_.end(),
                              [x] (double v) -> bool {return v > x;});

        return 0.0;
    }
};
