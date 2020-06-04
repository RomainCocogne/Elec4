/**
*   Description: Draw a fractal window
*                you can switch between mandelbrot and julia fractal
*   Author: Romain Cocogne
*   Version: 1.0
*/
#pragma once

#include <QtWidgets>
#include <vector>
#include <iostream>
#include <complex>
#include <cmath>
#include <thread>
#include "./util.h"

QT_BEGIN_NAMESPACE
class QImage;
QT_END_NAMESPACE

using std::get;
using std::vector;


class FractalImage: public QImage {
 protected:
    const int nmax_ = 512;  // for maximum iteration of loop
    const int ncolor_ = 65536;  // threshold for coloring pixel
    const Gradient grad = Gradient(2048);   // color gradient for coloring pixel

    double xc_;
    double  yc_;
    double d_;

    int w_;
    int h_;

    // draw (x,y) pixel using complex formula zn = zn*zn + c
    // xn0, yn0 are initial values of zn
    // x0, y0 are values of c
    void compute_pixel_complex(const double &xn0, const double &yn0,
                       const double &x0, const double &y0,
                       const int &x, const int &y);

    // draw (x,y) pixel using same formula as compute_pixel_complex
    // but without complex objects
    void compute_pixel(const double &xn0, const double &yn0,
                       const double &x0, const double &y0,
                       const int &x, const int &y);

    // draw one portion of fractal image
    void process_sub_image(int i, int m);

    // virtual method to be used as wrapper of
    // compute_pixel in child classes
    virtual void make_fractal_pixel(const double &x0, const double &y0,
                                    const int &x, const int &y) = 0;

 public:
    FractalImage(double xc, double yc, double d, int width, int height);
    FractalImage();

    // multi-threaded method
    // drawing fractal image
    void make_fractal();

};

/*
 * 2 types of fractals
 * using the same formula but not same initial conditions
 */

class MandelbrotImage: public FractalImage {
 public:
    MandelbrotImage(double xc, double yc, double d, int width, int height):
        FractalImage(xc, yc, d, width, height) {}
 protected:
    void make_fractal_pixel(const double &x0, const double &y0,
                            const int &x, const int &y) override {
        compute_pixel(0, 0, x0, y0, x, y);
    }
};

class JuliaImage: public FractalImage{
 public:
    JuliaImage(double xc, double yc, double d, int width, int height):
        FractalImage(xc, yc, d, width, height) {}
 protected:
    void make_fractal_pixel(const double &x0, const double &y0,
                            const int &x, const int &y) override {
        compute_pixel(x0, y0, -0.4, 0.6, x, y);
    }
};
