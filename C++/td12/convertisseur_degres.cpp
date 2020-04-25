// command: g++ convertisseur_degres.cpp $(pkg-config gtkmm-3.0 --cflags --libs)

#include <gtkmm/application.h>
#include "Controleur.hpp"
#include "VueGraphique.hpp"
#include "VueTextuelle.hpp"
#include "Modele.hpp"

int main(int argc, char* argv[]) {
    auto app = Gtk::Application::create(argc, argv);
    Modele *m = new Modele();
    VueGraphique *vg = new VueGraphique();
    VueTextuelle *vc = new VueTextuelle();
    Controleur *c = new Controleur(m, vg);
    m->ajouterObservateur(vg);
    m->ajouterObservateur(vc);
    return app->run(*vg);
}
