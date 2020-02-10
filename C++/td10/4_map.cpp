#include <iostream>
#include <forward_list>
#include "Dico.hpp"

int main(int argc, char const *argv[]) {
    Dico dico;
    std::string mot;
    while (std::cin >> mot)
        dico.inserer(mot);
    std::cout << dico << std::endl;
    return 0;
}
