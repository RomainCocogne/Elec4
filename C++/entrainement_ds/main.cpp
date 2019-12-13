#include "Polygone.hpp"
#include "String.hpp"
#include "ListeChainee.hpp"
#include "PileChainee.hpp"
#include <iostream>
int main(int argc, char const *argv[])
{
	String toto ("toto");
	String titi = toto;
	titi[1] ='i';
	titi[3]= 'i';

	String tototiti = toto+titi;
	String tototititoto = tototiti;
	tototititoto = tototiti+toto;
	std::cout << toto << std::endl;
	std::cout << titi << std::endl;
	std::cout << tototiti << std::endl;
	std::cout << tototititoto << std::endl;
	return 0;
}