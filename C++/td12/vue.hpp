#pragma once
#include <gtkmm/button.h>
#include <gtkmm/window.h>
#include <gtkmm/image.h>
#include <gtkmm/box.h>
#include <string>

class Vue : public Gtk::Window {
 private:
    const std::string img1_name_ = "/home/romain/Images/chatonBrutal.jpeg";
    const std::string img2_name_ = "/home/romain/Images/Vincent_granet_visage.jpeg";
    Gtk::Box box;
    Gtk::Button bClose;
    Gtk::Button bPermut;
    Gtk::Image img1;
    Gtk::Image img2;

    void close() { hide(); }
    void permute_img() {
        static bool flip = false;
        // img1.set_visible(!img1.get_visible());
        // img2.set_visible(!img2.get_visible());
        img1.set(flip ? img1_name_: img2_name_);
        flip = !flip;
    }

 public:
    Vue(): box(Gtk::ORIENTATION_VERTICAL),
           bClose("Close"), bPermut("Permuter"),
           img1(img1_name_)/*,
           img2(img2_name_)*/ {
        bClose.signal_clicked().connect(sigc::mem_fun(*this, &Vue::close));
        bPermut.signal_clicked().connect(sigc::mem_fun(*this, &Vue::permute_img));
        box.pack_start(img1);
        // box.pack_start(img2);
        box.pack_start(bPermut);
        box.pack_start(bClose);
        add(box);
        show_all_children();
        // img2.set_visible(false);
    }
// le destructeur
    virtual ~Vue() {}
};
