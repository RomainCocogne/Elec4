
#include <iostream>
#include <cstdlib>


class rectangle
{
private:
	double largeur, longueur;
public:
	rectangle(double la=0, double lo=0){
		this->largeur=la; this->longueur = lo;
	}

	int compareTo (const rectangle &c) const {
		return surface() < c.surface() ? -1 :  surface() == c.surface() ? 0 : 1;
	}
	bool operator < (const rectangle &c) const {
		return compareTo(c) == -1;
	}

	friend std::ostream& operator << (std::ostream &f,const rectangle &r) {
		return f << "(" << r.largeur << "," << r.longueur << ")";
	}

	double surface () const {
		return largeur*longueur;
	}
	
};