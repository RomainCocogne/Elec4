#include "fractal.h"

FractalImage::FractalImage(double xc, double yc, double d, int width, int height):
    QImage(width, height, QImage::Format_RGB32),
    xc_{xc}, yc_{yc}, d_{d},
    w_{width}, h_{height} {}

FractalImage::FractalImage():
    QImage(600, 400, QImage::Format_RGB32),
    xc_{-0.5}, yc_{0}, d_{1},
    w_{600}, h_{400} {}

void FractalImage::make_fractal() {
    std::vector<std::thread> threads;
    int max_threads = 4;    // number of threads
    for (int i = 0; i < max_threads; i++) {
        threads.emplace_back([=]() {
            process_sub_image(i, max_threads);
        });
    }
    for (auto &thread_elem : threads)   // joins threads
        thread_elem.join();
}

void FractalImage::process_sub_image(int i, int m) {
    // Transformation from plan (w,h) to plan (x,y)
    Map<double> y_displ_to_plan(0,  h_, yc_+d_, yc_-d_);
    Map<double> x_displ_to_plan(0,  w_, xc_-1.5*d_, xc_+1.5*d_);

    // for multi-threading
    const int ypos_start = i*(h_)/m;
    const int ypos_stop  = (i+1)*(h_)/m;

    // draw the fractal
    for (int y = ypos_start; y < ypos_stop; ++y) {
        auto y0 = y_displ_to_plan(y);
        for (int x = 0; x < w_; ++x) {
            auto x0 = x_displ_to_plan(x);
            make_fractal_pixel(x0, y0, x, y);
        }
    }
}

void FractalImage::compute_pixel_complex(const double &xn0, const double &yn0,
                   const double &x0, const double &y0,
                   const int &x, const int &y) {

    std::complex<double> zn(xn0, yn0);  // first element
    std::complex<double> c(x0, y0);
    bool inside_fract = true;
    int n;
    for (n = 0; n <nmax_; ++n) {
        zn = zn*zn + c; // next element
        if (!(std::norm(zn) < ncolor_)) {   // test convergence
            inside_fract = false;
            break;
        }
    }
    if (inside_fract) { // fill the inside in black
        setPixel(x, y, qRgb(0, 0, 0));
    } else {    // compute the pixel color
        double v = log2(log2((std::norm(zn))));
        int i = (1024*sqrt(n+5-v));
        setPixel(x, y, grad[i%2048]);
    }
}


void FractalImage::compute_pixel(const double &xn0, const double &yn0,
                   const double &x0, const double &y0,
                   const int &x, const int &y) {
    double xn = xn0;
    double yn = yn0;
    double xn_square = xn*xn;
    double yn_square = yn*yn;
    auto abs_zn = xn_square+yn_square;
    bool inside_fract = true;
    int n;
    for (n = 0; n <nmax_; ++n) {
        yn = 2*xn*yn +y0;   // imaginary part
        xn = xn_square - yn_square + x0;    // real part
        xn_square = xn * xn;    // do this operation only one time
        yn_square = yn * yn;

        abs_zn = xn_square+yn_square;   // same as std::norm in complex method
        if (!(abs_zn < ncolor_)) {
            inside_fract = false;
            break;
        }
    }
    if (inside_fract) {
        setPixel(x, y, qRgb(0, 0, 0));
    } else {
        double v = log2(log2((abs_zn)));
        int i = (1024*sqrt(n+5-v));
        setPixel(x, y, grad[i%2048]);
    }
}
