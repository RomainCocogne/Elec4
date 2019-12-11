#include "pile_tableau.hpp"
#include "pile_chainee.hpp"
#include "rectangle.hpp"
#include <iostream>

int main(int argc, char const *argv[])
{
	PileTableau<int> p1 = PileTableau<int>();
	PileTableau<int> p2 = PileTableau<int>();
	p1.empiler(5);
	p1.empiler(8);
	PileTableau<int> p3 = p1;
	p2=p1;
	p1.empiler(10);
	p3.depiler();
	std::cout << p1.get_sommet() << std::endl;
	std::cout << p1 << std::endl << p2 << std::endl << p3 << std::endl;

	PileTableau<rectangle> ptr = PileTableau<rectangle> (3);
	ptr.empiler(*new rectangle(3,8));
	PileChainee <PileTableau<rectangle>> pcptr;
	pcptr.empiler(ptr);
	pcptr.sommet().empiler(*new rectangle(8.3,7));
	pcptr.empiler(ptr);
	std::cout << pcptr << std::endl;
	return 0;
}