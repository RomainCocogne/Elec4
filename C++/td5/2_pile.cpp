#include "pile_chainee.hpp"
#include <iostream>
#include <cstdlib>

int main(int argc, char const *argv[])
{
	PileChainee p = PileChainee ();
	PileChainee p2;
	std::cout  << p.estVide () << std::endl;
	p.empiler (7);
	p.empiler (8);
	p.empiler (6);
	p.empiler (15);
	p2 = p;
	std::cout  << p.sommet () << std::endl;
	std::cout  << p.estVide () << std::endl;
	std::cout  << p.sommet () << std::endl;
	p.depiler ();
	std::cout  << p << std::endl;
	std::cout  << p2 << std::endl;
	
	return 0;
}