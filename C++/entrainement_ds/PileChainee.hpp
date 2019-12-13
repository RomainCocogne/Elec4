#pragma once
#include "ListeChainee.hpp"
#include "Pile.hpp"
template <typename T>
class PileChainee: public Pile<T>, public ListeChainee<T>
{
public:
	PileChainee(): ListeChainee<T>(){}
	~PileChainee(){
		delete this;
	}
	
	int estVide() override { return ListeChainee<T>::longueur() == 0;}
	void empiler (const T &x) override {ListeChainee<T>::inserer(x,0);}
	void depiler () override{ListeChainee<T>::supprimer(0);}
	T &sommet () override{return ListeChainee<T>::ieme(0);}
};