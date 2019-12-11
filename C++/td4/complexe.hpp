#pragma once
#include <iostream>
#include <cmath>
#include <fstream>

class Complexe 
{
	private:
		double preelle;
		double pimg;
	public:
		static const Complexe I;
		
		Complexe (double r = 0, double i = 0): preelle (r), pimg (i) {}
		// ~Complexe(){std::cout << "destruction" << std::endl;}

// get functions
		double getReelle () const { return this->preelle; } //if implementation in complexe.cpp, name is double Complexe::getReelle () const
		double getImg    () const { return this->pimg ;   }

// set functions
		void setReelle (const double r) { this->preelle = r;}
		void setImg    (const double i) { this->pimg = i;   }

// ecriture de complexe
		void ecrireComplexe(std::ostream &st = std::cout) { st << "(" << this->preelle << "," << this->pimg << ")"; }
		void lireComplexe(std::istream &st = std::cin) {  }

// operations
		double rho   () { return pow(pow(this->preelle,2) + pow(this->pimg,2) , 0.5); }
		double theta () { return atan2 (this->pimg, this->preelle); 				  }

		Complexe plus (const Complexe &c) const
		{
			Complexe res (this->preelle+c.getReelle(), this->pimg+c.getImg());
			return res;
		}

		Complexe operator+(const Complexe &c) const 
		{
			return this->plus(c);
		};
//contenu du fichier format binaire
		// friend std::ofstream& operator << (std::ofstream& f,const Complexe& c){
		// 	f.write((char*) &c, sizeof(Complexe));
		// 	return f;
		// }
		// friend std::ifstream& operator >> (std::ifstream& f, Complexe& c){
		// 	f.read((char*) &c, sizeof(Complexe));
		// 	return f;
		// }
//fichier format textuel
		friend std::ostream& operator << (std::ostream& f, Complexe& c){
			c.ecrireComplexe(f);
			return f;
		}
		friend std::istream& operator >> (std::istream& f, Complexe& c){
			c.lireComplexe(f);
			return f;
		}

		static Complexe polComplexe (const double rho, const double theta)
		{
			Complexe c (rho*cos(theta), rho*sin(theta));
			return c;
		}
};

const Complexe Complexe::I = Complexe (0,1);