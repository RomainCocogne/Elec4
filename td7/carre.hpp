#pragma once

#include <iostream>
#include <cstdlib>
#include "figure.hpp"
#include "rectangle.hpp"


class Carre: public Rectangle
{
public:
	Carre(const double c=0.0): Rectangle(c,c){}
	~Carre(){
		std::cout << "destruction carre" << std::endl;
	}

	std::string type(){
		return "Carre";
	}

	Carre (const Rectangle &r): Rectangle(r.getLargeur(),r.getLongueur()) {}
	void setLargeur(const double l) = delete;
	void setLongeur(const double L) = delete;
	double getLargeur() const = delete;
	double getLongueur() const = delete;
	
	void setCote(const double c) {Rectangle::setLargeur(c); Rectangle::setLongeur(c);}	
	double getCote (){ return Rectangle::getLongueur();}
	
};