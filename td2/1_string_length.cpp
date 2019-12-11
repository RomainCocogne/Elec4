#include <string>
#include <cstdlib>
#include <iostream>

int main(int argc, char const *argv[])
{
	std::string s;
	std::cout << "Chaine de caracteres : "; std::cin >> s;
	std::cout << s << " : " << s.length() << std::endl;
	return 0;
}