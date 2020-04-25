#pragma once
#include <gtkmm/button.h>
#include <gtkmm/window.h>
#include <gtkmm/entry.h>
#include <gtkmm/box.h>
#include <functional>
#include <iomanip>
#include "Observateur.hpp"
// #include "Controleur.hpp"

class VueGraphique: public Observateur<double>, public Gtk::Window {
 private:
    Gtk::Box box_;
    Gtk::Box box_button_;
    Gtk::Button celsius_;
    Gtk::Button fahrenheit_;
    Gtk::Button exit_;
    Gtk::Entry txt_degres_;


 public:
    void close() { hide(); }
    void update(double info) override {
        Glib::ustring ustr =Glib::ustring::format(std::fixed, std::setprecision(2), info);
        txt_degres_.set_text(ustr);
    }

    double get_temp() {
        const char* str = txt_degres_.get_text().c_str();
        double t = atof(str);
        return t;
     }

    void set_celsius_listener(std::function<void(void)> f) {
        celsius_.signal_clicked().connect([=](){f();});
    }
    void set_fahrenheit_listener(std::function<void(void)> f) {
        fahrenheit_.signal_clicked().connect([=](){f();});
    }
    void set_exit_listener(std::function<void(void)> f) {
        exit_.signal_clicked().connect([=](){f();});
    }
    VueGraphique(): box_(Gtk::ORIENTATION_VERTICAL),
                    box_button_(Gtk::ORIENTATION_HORIZONTAL),
                    celsius_("Celsius"), fahrenheit_("Fahrenheit"),
                    exit_("Exit") {

        set_size_request(200, 50);
        txt_degres_.set_text("0.0");
        txt_degres_.select_region(0, txt_degres_.get_text_length());

        box_button_.pack_start(celsius_);
        box_button_.pack_start(fahrenheit_);
        box_button_.pack_start(exit_);

        box_.pack_start(txt_degres_);
        box_.pack_start(box_button_);

        add(box_);
        show_all_children();
    }
};
