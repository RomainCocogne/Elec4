#pragma once

class Parallelogramme{
protected:
    double L, l, a;

public:
    Parallelogramme(double la, double lo, double an): L(la), l(lo), a(an){}

    void allongerX(double la){ this->l=la;}
    void allongerX(double lo){ this->L=lo;}
};

class Rectangle: virtual public Parallelogramme{
public:
    Rectangle(double la, double lo): Parallelogramme(la,lo,90){}
};
class Losange: virtual public Parallelogramme{
public:
    Losange (double l, double a): Parallelogramme(l,l,a){}
};

class Carre: public Rectangle, public Losange{
public:
    Carre (double l): Parallelogramme(l,l,90){}
};
