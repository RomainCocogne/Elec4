/**
*   Description: Some util classes
*   Author: Romain Cocogne
*   Version: 1.0
*/
#pragma once
#include <QColor>
#include <vector>
#include <algorithm>
#include <iostream>
#include <sstream>
#include <string>

using std::ostringstream;
using std::string;
using std::vector;

// Map a value from one interval to another
// Can map all values of vector
template <typename T>
class Map {
 private:
    T min_from_;
    T max_from_;
    T min_to_;
    T max_to_;
 public:
    Map() = default;
    Map(T min1, T max1, T min2, T max2):
        min_from_{min1}, max_from_{max1},
        min_to_{min2}, max_to_{max2} {}

    T operator ()(const T &p) {
        return (p - min_from_)/(max_from_-min_from_)
                *(max_to_-min_to_) + min_to_;
    }

    vector<T> operator () (const vector<T> &p_vect){
        vector<T> p_maped;
        p_maped.reserve(p_vect.size());
        for (auto p : p_vect) {
            p_maped.push_back((p - min_from_)/(max_from_-min_from_)
                                *(max_to_-min_to_) + min_to_);
        }
        return p_maped;
    }
};

// Clamp a value with given min and max
template <typename T>
class Clamp {
 private:
    T min_;
    T max_;
 public:
    Clamp(T min, T max): min_{min}, max_{max} {}
    T operator () (const T &val) {
        return (val < min_) ? min_ : ((val > max_)? max_ : val );
    }
};

// Do a linear interpolation unto normalized vectors
class Linear{
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
    double operator() (const double &x) {
        if (x < 0)
            return a_[0] * (-x_[0]) + b_[0];
        auto i = x_.size()-1;
        if (x > 1)
            return a_[i] * (1 - x_[i]) + b_[i];
        while (i > 0  && x < x_[i]) --i;
        return a_[i] * (x - x_[i]) + b_[i];
    }
};

// Commify unsigned lon int value
class Commify {
 private:
    uint32_t val_;
 public:
    explicit Commify(uint32_t value):val_{value} {}

    friend std::ostream &operator << (std::ostream &f, const Commify &c){
        ostringstream ss;
        ss << c.val_;
        string s = ss.str();
        int insertPosition = s.length() - 3;
        while (insertPosition > 0) {
            s.insert(insertPosition, ",");
            insertPosition -= 3;
        }
        f << s;
        return f;
    }
};

// make a RGB color gradient
// with the linear interpolation method
// and save it in a vector
class Gradient {
 private:
    const vector<double> xs_ { 0., 0.16, 0.42, 0.6425, 0.8575 };
    const vector<double> yr_ { 0., 32. , 237. , 215., 0. };
    const vector<double> yg_ { 7., 107. , 255. , 170., 10. };
    const vector<double> yb_ { 100., 183. , 235. , 40., 15. };

    // values of gradient
    vector<QRgb> color_tab_;

 public:
    // Constructor of the gradient
    // i is the size of the resulting vector
    Gradient(const int &i) {
        color_tab_.reserve(i);

        // using same gradient as in SlineImage class
        Map<double> x_normalized(0, i, -0.05, 1.05);
        Clamp<double> clamp_to_rgb(0, 255);

        Linear splineGreen(xs_, yg_);
        Linear splineBlue(xs_, yb_);
        Linear splineRed(xs_, yr_);

        for (auto x = 0; x < i; ++x){
            double x_n = x_normalized(x);
            int r=clamp_to_rgb(splineRed(x_n));
            int g=clamp_to_rgb(splineGreen(x_n));
            int b=clamp_to_rgb(splineBlue(x_n));
            color_tab_[x] = qRgb(r, g, b);
        }
    }

    // to be used as an array
    QRgb operator [] (const int &i) const{
        return color_tab_[i];
    }
};


