#pragma once

#include <cmath>
#include <iostream>
#include "figure.hpp"
#include "ellipse.hpp"

class Cercle: public Ellipse
{
public:
	Cercle(const double r=0.0): Ellipse(r,r){}
	~Cercle(){
		std::cout << "destruction cercle" << std::endl;
	}

	std::string type(){
		return "Cercle";
	}

	double getPetitRayon () const = delete;
	double getGrandRayon () const = delete;
	void setPetitRayon (const double a) = delete;
	void setGrandRayon (const double b) = delete;
	
	double getRayon() const { return Ellipse::getPetitRayon();}
	void setRayon (const double r) { Ellipse::setPetitRayon(r); Ellipse::setGrandRayon(r);}
};