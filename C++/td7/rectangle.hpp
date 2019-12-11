
#pragma once

#include <iostream>
#include <cstdlib>
#include "figure.hpp"

class Rectangle: public Figure
{
protected:
	double largeur, longueur;

	void print (std::ostream &f) {
		f << "(" << this->largeur << "," << this->longueur << ")";
	}

public:
	Rectangle(const double l=0.0, const double L=0.0): largeur(l), longueur(L){}
	~Rectangle(){
		std::cout << "destruction rectangle" << std::endl;
	}

	Rectangle (const Rectangle &r){this->largeur=r.largeur; this->longueur=r.longueur;}

	std::string type(){
		return "Rectangle";
	}

	double getLargeur() const {return this->largeur;}
	double getLongueur() const {return this->longueur;}

	void setLargeur(const double l) {this->largeur = l;}
	void setLongeur(const double L) {this->longueur = L;}

	double perimetre() const {return 2*this->largeur+2*this->longueur;}
	double surface() const {return this->largeur*this->longueur;} 	

	int compareTo (const Rectangle &c) const {
		return surface() < c.surface() ? -1 :  surface() == c.surface() ? 0 : 1;
	}
	bool operator < (const Rectangle &c) const {
		return compareTo(c) == -1;
	}
	
	
};
