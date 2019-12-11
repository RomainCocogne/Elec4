#pragma once
#include <iostream>
#include <cassert> 
#include <sstream>

template <typename T>

class PileTableau
{
private:
	int sommet,max;
	T *elts;

	void dupliquer (const PileTableau<T> &p){
		assert (this->max == p.max);
		for (int i = 0; i < p.sommet; ++i)
			this->elts[i] = p.elts[i];
		this->sommet = p.sommet;
	}

	std::string toString (){
		std::ostringstream s;
		s << "[";
		if (sommet >0) s <<  (elts[0]);
		for (int i = 1; i < sommet; ++i)
		{
			s << "," << elts[i];
		}
		s << "]";
		return s.str();
	}

	void print_pile(std::ostream &st = std::cout){
		st << toString();
	}

public:

	PileTableau(int n = 100){
		sommet=0;
		max=n;
		elts = new T [n];
	}
	~PileTableau(){
		delete[] elts;
	}

	
	PileTableau (const PileTableau<T> &p){
		this->elts= new T[this->max = p.max];
		this->dupliquer(p);
	}
	PileTableau &operator = (const PileTableau &p){
		this->elts = new T [this->max = p.max];
		this->dupliquer(p);
		return *this;
	}

	bool estVide () const{
		return sommet == 0;
	}

	const T &get_sommet () const{
		return elts[sommet-1];
	}

	void empiler (T e){
		if(sommet !=max){
			elts[this->sommet++]=e;
		}
	}

	void depiler (){
		if(sommet>0)
			this->sommet --;
	}
	
	friend std::ostream& operator << (std::ostream& f, PileTableau& p){
		p.print_pile(f);
		return f;
	}

};