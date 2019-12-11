#pragma once

#include <iostream>
#include <cstdlib>
#include <string>

class noeud{
private:
	noeud *suivant;
	int val;
public:
	noeud (int v = 0, noeud * s = nullptr){ this->val=v; this->suivant=s;}
	int getVal(){ return val;}
	noeud * getSuivant(){ return suivant;}
	void setVal(int val){ this->val=val;}
	void setSuivant(noeud *s){this->suivant=s;}
};

class PileChainee{
private:
	noeud *pic;

	noeud *dupliquer (noeud *n){
		if (n == nullptr) return nullptr;
		noeud * p = dupliquer (n->getSuivant());
		return new noeud (n->getVal(), p);
	}

	std::string toString (){
		std::string s = "->" + std::to_string(this->pic->getVal());
		noeud *temp = this->pic->getSuivant();
		while (temp != nullptr){
			s+= "->"+std::to_string(temp->getVal());
			temp = temp->getSuivant();
		} 
		return s;
	}

	void print_pile (std::ostream &st = std::cout){
		st << toString();
	}

public:

	PileChainee (noeud *p = nullptr){this->pic=p;}
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

	int estVide(){	return this->pic == PileVide.pic;}

	void empiler(int val){ 
		noeud *new_pic= new noeud (val,this->pic);
		this->pic=new_pic;
	}
	void depiler(){
		noeud *temp = this->pic->getSuivant();
		delete this->pic;
		this->pic=temp;
	}
	int sommet(){
		return this->pic->getVal();
	}
};

const PileChainee PileChainee::PileVide = PileChainee();