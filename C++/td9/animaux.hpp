#pragma once
#include <iostream>

class animal{
protected:
    double ration;
public:
    animal(const double r = 0.0): ration(r){}
    virtual void jeMange() = 0;
    double getRation(){ return this->ration;}
};

class herbivore: public virtual animal{
private:
    typedef animal super; // simuler le mot clee super en c++
public:
    herbivore(const double r = 0.0):animal(r){}
    void jeMange() override { std::cout << super::getRation() << " kilos d'herbe";}
};
class carnivore: public virtual animal{
private:
    typedef animal super;
public:
    carnivore(const double r = 0.0):animal(r){}
    void jeMange() override{ std::cout << super::getRation() << " kilos de viande";}
};

class omnivore: public herbivore, public carnivore{
public:
    omnivore(const double r = 0.0):animal(r), herbivore(r), carnivore(r){}
    void jeMange() override {std::cout << animal::getRation() << " kilos d'herbe et de viande"; }
};
