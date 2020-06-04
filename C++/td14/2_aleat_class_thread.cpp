
#include <chrono>
#include <ctime>
#include <iostream>
#include <cstdlib>
#include "Aleatoire.hpp"

int main() {
    Aleatoire t0(1);
    Aleatoire t1(1);
    Aleatoire t2(1);

    t0.start();
    t1.start();
    t2.start();
    
    t0.join();
    t1.join();
    t2.join();

    return EXIT_SUCCESS;
}