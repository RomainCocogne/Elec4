#include <iostream>
#include <string>
#include "rectangle.hpp"

template <typename T> 
const T& minimum (const T& x, const T& y){
	return x < y ? x : y;
}

int main(int argc, char const *argv[])
{
	std::cout << minimum(3,4) << std::endl;
	std::cout << minimum ("abc","cba") << std::endl;
	std::cout << minimum <double> (6.3, 8) << std::endl;
	std::cout << minimum <int> (13, 4.8) << std::endl;

	rectangle r1 = rectangle (2.2,7);
	rectangle r2 = rectangle (8.1,4.3);

	std::cout  << minimum(r1 ,r2) << std::endl;
	return 0;
}