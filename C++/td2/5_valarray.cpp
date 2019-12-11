#include <valarray>
#include <cstdlib>
#include <iostream>

double produitScalaire ( std::valarray <double> v1 , std::valarray <double> v2 )
{
	if (v1.size() != v2.size())
		return EXIT_FAILURE;
	double ps=0;
	for (int i = 0; i< (int) v1.size(); i++)
		ps+=v1[i]*v2[i];
	return ps;
}
int main(int argc, char const *argv[])
{
	std::valarray <double> v1 = {1.0,2.0};
	std::valarray <double> v2 = {3.0,2.0};
	
	std::cout << produitScalaire(v1,v2) << std::endl;
	return 0;
}