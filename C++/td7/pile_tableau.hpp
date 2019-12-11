#pragma once
#include <iostream>
#include <cassert> 
#include <sstream>
#include "pile.hpp"

template <typename T>

class PileTableau: public Pile<T>
{
private:
	int s,max;
	T *elts;

	void dupliquer (const PileTableau<T> &p){
		assert (this->max == p.max);
		for (int i = 0; i < p.s; ++i)
			this->elts[i] = p.elts[i];
		this->s = p.s;
	}

	std::string toString (){
		std::ostringstream os;
		os << "[";
		if (s >0) os <<  (elts[0]);
		for (int i = 1; i < s; ++i)
		{
			os << "," << elts[i];
		}
		os << "]";
		return os.str();
	}


public:

	PileTableau(int n = 100){
		s=0;
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
		return s == 0;
	}

	const T sommet () const{
		return elts[s-1];
	}

	void empiler (T e){
		if(s !=max){
			elts[this->s++]=e;
		}
	}

	void depiler (){
		if(s>0)
			this->s --;
	}
	
	// friend std::ostream& operator << (std::ostream& f, PileTableau& p){
	// 	p.print_pile(f);
	// 	return f;
	// }

};