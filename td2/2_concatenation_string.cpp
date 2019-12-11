#include <string>
#include <iostream>
#include <cstring>

int main(int argc, char const *argv[])
{
	std::string s1 = "Bonjour", s2 = " a tous", s3, s4;
	std::cout << (s3 = s1+s2) << std::endl;
	
	s4 = s3;
	
	std::cout << s4 << std::endl << std::endl;

	s4[0] = 'b';

	std::cout << s3 << std::endl;
	std::cout << s4 << std::endl;
	return 0;
}