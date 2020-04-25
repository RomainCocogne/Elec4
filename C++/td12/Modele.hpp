#pragma once
#include "Observable.hpp"

class Modele: public Observable <double> {
 private:
    double degres_;

 public:
    Modele(): degres_{0} {}
    void convertirEnFahrenheit(const double &c) {
        degres_ = 1.8*c+32;
        notifierObservateurs(degres_);
    }
    void convertirEnCelsius(const double &f) {
        degres_ = (f-32)/1.8;
        notifierObservateurs(degres_);
    }
};
