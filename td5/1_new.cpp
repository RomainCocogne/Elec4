#include <iostream>
#include "../td4/complexe.hpp"

int main(int argc, char const *argv[])
{
	Complexe *pc0 = new Complexe (3.1,  6.56);
	Complexe **pc =new Complexe *[5];
	int* pi =new int[10];
	pc[1]= new Complexe(1,2);
	std::cout << *pc[1] << std::endl;
	std::cout << pi[2]<< std::endl;
	std::cout << pc0->getImg() << std::endl;
	delete pc0;
	delete [] pc;

	Complexe  c3 (1.2 ,56.9);
	std::cout << "c3=" << c3 << std::endl;
	return 0;
}