#pragma once
#include <iostream>
#include "Observateur.hpp"

class VueTextuelle: public Observateur<double>{
 public:
    void update(double d) { std::cout << d << std::endl;}
};
