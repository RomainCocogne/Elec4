#pragma once

#include <cmath>
#include <iostream>
#include "figure.hpp"

class Ellipse: public Figure
{
protected:
	double prayon, grayon;
	void print (std::ostream &f) {
		f << "(" << this->prayon << "," << this->prayon << ")";
	}
public:
	Ellipse(const double a=0.0, const double b=0.0): prayon(a), grayon(b){}
	~Ellipse(){
		std::cout << "destruction ellipse" << std::endl;
	}

	std::string type(){
		return "Ellipse";
	}

	double getPetitRayon () const {return prayon;}
	double getGrandRayon () const {return grayon;}

	void setPetitRayon (const double a){ this->prayon=a;}
	void setGrandRayon (const double b){ this->grayon=b;}

	double perimetre() const { return M_PI*sqrt(2*(prayon*prayon+grayon*grayon));}
	double surface () const { return M_PI*prayon*grayon;}
};

