#include <iostream>
#include <fstream>
#include <cstdlib>
#include "complexe.hpp"


void print_file_Complexe (){
	std::ifstream fios("fc");
	if(!fios.is_open()){
		perror("fc");
		exit(EXIT_FAILURE);
	}

	Complexe c;

	while(!fios.eof()){
		fios >> c;
		std::cout << c << std::endl;
	}
	fios.close();
}

int main(int argc, char const *argv[])
{
	std::ofstream foos("fc");
	if(!foos.is_open()){
		perror("fc");
		exit(EXIT_FAILURE);
	}

	int n;
	std::cout << "Nombre de complexes : "; std::cin >> n;

	for (int i=0; i<n; i++){
		double r, im;
		std::cout << "Complexe " << i+1 << " reel : "; std::cin >> r;
		std::cout << "Complexe " << i+1 << " imaginaire : "; std::cin >> im;
		Complexe c = Complexe (r,im);
		foos << c;
	}
	foos.close ();

	print_file_Complexe();

	return 0;
}