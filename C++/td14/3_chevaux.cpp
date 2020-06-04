
#include <vector>
#include <cstdlib>
#include <iostream>
#include "Course.hpp"

int main() {
    std::vector<std::string> chevaux =
        {"Easy Rider", "Joli Coeur", "Étoile Filante", "Belle de nuit"};
        // créer une course
        Course c(chevaux);
        // lancer la course
        c.run();
        // afficher les résultats
        std::cout << c.donnerLesResultats();

        return EXIT_SUCCESS;
    }