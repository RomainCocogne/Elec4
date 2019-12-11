#include <iostream>
#include "rectangle.hpp"
#include "ellipse.hpp"
#include "carre.hpp"
#include "cercle.hpp"
#include "figure.hpp"
#include <vector> 

void afficherType (Figure *f){
	std::cout << f->type() << std::endl;
}

int main(int argc, char const *argv[])
{
	Rectangle r1 (2.6,4.42), r2 = Carre(8.1);
	Carre c1 = r2;
	std::cout << r1.perimetre() << std::endl;
	std::cout << c1.perimetre() << std::endl;
	c1.setCote(3.9);

	Ellipse e1 (3.5,4.2);
	Cercle ce1;
	ce1.setRayon(2.3);
	std::cout << e1.perimetre() << std::endl;
	std::cout << c1.surface() << std::endl;

	std::cout << std::endl << "-------------" << std::endl;
	std::vector<Figure*> vf = { new Cercle(2)};
	vf.insert(vf.begin(),new Rectangle(2.3,5.1));
	vf.insert(vf.begin(),new Ellipse(2.3,5.1));
	vf.insert(vf.begin(),new Carre(2.3));
	vf.insert(vf.begin(),new Cercle(5.1));

	for (Figure *f: vf){
		afficherType(f);
		std::cout << f->surface() << std::endl;
	}

	std::cout << std::endl << "-------------" << std::endl;

	return 0;
}