#pragma once

#include <iostream>
#include <cstdlib>
#include <string>
#include <sstream>

template <typename T>

class noeud{
private:
	noeud<T> *suivant;
	T val;
public:
	noeud (T v = 0, noeud <T>* s = nullptr){ this->val=v; this->suivant=s;}
	T getVal(){ return val;}
	noeud<T> * getSuivant(){ return suivant;}
	void setVal(T val){ this->val=val;}
	void setSuivant(noeud<T> *s){this->suivant=s;}
};

template <typename T>

class PileChainee{
private:
	noeud<T> *pic;

	noeud<T> *dupliquer (noeud<T> *n){
		if (n == nullptr) return nullptr;
		noeud<T> * p = dupliquer (n->getSuivant());
		return new noeud<T> (n->getVal(), p);
	}

	std::string toString (){
		std::ostringstream s;
		s <<  "->" << (this->pic->getVal());
		noeud<T> *temp = this->pic->getSuivant();
		while (temp != nullptr){
			s << "->" << (temp->getVal());
			temp = temp->getSuivant();
		} 
		return s.str();
	}

	void print_pile (std::ostream &st = std::cout){
		st << toString();
	}

public:

	PileChainee (noeud<T> *p = nullptr){this->pic=p;}
	~PileChainee(){
		while(!this->estVide())
			this->depiler();
	}
	PileChainee (const PileChainee &p){
		this->pic =dupliquer(p.pic);
	}
	PileChainee &operator = (const PileChainee &p){
		pic = dupliquer(p.pic);
		return *this;
	}


	friend std::ostream& operator << (std::ostream& f, PileChainee& p){
		p.print_pile(f);
		return f;
	}

	static const PileChainee PileVide;

	int estVide(){	return this->pic == nullptr;}

	void empiler(T val){ 
		noeud<T> *new_pic= new noeud<T> (val,this->pic);
		this->pic=new_pic;
	}
	void depiler(){
		noeud<T> *temp = this->pic->getSuivant();
		delete this->pic;
		this->pic=temp;
	}
	T sommet(){
		return this->pic->getVal();
	}
};
