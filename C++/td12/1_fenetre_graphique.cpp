// command: g++ 1_fenetre_graphique.cpp $(pkg-config gtkmm-3.0 --cflags --libs)

#include <gtkmm/application.h>
#include "vue.hpp"

int main(int argc, char *argv[]) {
    auto app = Gtk::Application::create(argc, argv);
    return app->run(* new Vue ());
}
