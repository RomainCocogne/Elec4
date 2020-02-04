#include <iostream>
#include "Pile.hpp"


int main()
{
    Pile<int> i;
    std::cout <<"Pile vide: " << i.estVide() << std::endl;
    i.empiler(0);
    i.empiler(2);
    i.empiler(3);
    std::cout << i << std::endl;
    i.depiler();
    std::cout << i << std::endl;
    std::cout << "Pile vide: " << i.estVide() << std::endl;
    return 0;
}
