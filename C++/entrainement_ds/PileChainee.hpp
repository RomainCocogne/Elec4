#pragma once
#include "ListeChainee.hpp"
#include "Pile.hpp"

class PileVideException: std::exception{
public:
    const char * what () const noexcept override{
        return "Pile Vide";
    }
};
template <typename T>
class PileChainee: public Pile<T>
{
private:
    ListeChainee<T> l;
public:
	PileChainee(){}
	~PileChainee(){
		delete this;
	}


	int estVide() override { return l.longueur() == 0;}
	void empiler (const T &x) override {l.inserer(x,0);}
	void depiler () override{
        if (this->estVide()) throw PileVideException();
	    l.supprimer(0);
    }
	T &sommet () override{
        if (this->estVide()) throw PileVideException();
	    return l.ieme(0);
    }
};
