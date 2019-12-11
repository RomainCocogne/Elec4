
#include "complexe.hpp"
#include <iostream>

int main(int argc, char const *argv[])
{
	std::cout << "I : " ; (Complexe::I).getImg() ; std::cout << std::endl;	

	Complexe c1, c2 (4.5), c3 (3.2,8.9);

	std::cout << "c1 : " ; c1.ecrireComplexe() ; std::cout << std::endl;
	std::cout << "c2 : " ; c2.ecrireComplexe() ; std::cout << std::endl;
	std::cout << "c3 : " ; c3.ecrireComplexe() ; std::cout << std::endl;

	(Complexe::polComplexe(4.3,1.2)).ecrireComplexe(); std::cout << std::endl;
	(c2+c3).ecrireComplexe(); std::cout << std::endl;

	return 0;
}