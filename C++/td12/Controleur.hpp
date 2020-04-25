#pragma once
#include "VueGraphique.hpp"
#include "Modele.hpp"

class Controleur {
 private:
    VueGraphique *vue_;
    Modele *model_;
 public:
    Controleur(Modele *model, VueGraphique *vue):
        vue_{vue}, model_{model} {
        vue_->set_celsius_listener(std::bind(&Controleur::celsius, this));
        vue_->set_fahrenheit_listener(std::bind(&Controleur::fahrenheit, this));
        vue_->set_exit_listener(std::bind(&Controleur::close, this));
        }

    void celsius() {
        model_->convertirEnCelsius(vue_->get_temp());
    }
    void fahrenheit() {
        model_->convertirEnFahrenheit(vue_->get_temp());
    }
    void close() {
        vue_->close();
    }
};
