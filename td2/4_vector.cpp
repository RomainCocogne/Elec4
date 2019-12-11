#include <string>
#include <cstdlib>
#include <vector>
#include <iostream>

void afficherVecteur(std::vector <auto> vector){
	for (auto v : vector)
		std::cout << v << " ";
	std::cout << std::endl;
}


void vecteurPair (std::vector<int> &v, int n){
	for (int i = 0; i<n; i++)
		v.push_back(2*i);
}

void vecteurPairImpair (std::vector<int> &v){
	int imp = 1, size = v.size();
	for ( int i = 0; i < size; i++, imp+=2)
		v.insert(v.begin()+imp,imp);
}

int main(int argc, char const *argv[])
{


	std::vector<int> v1;
	std::vector<std::string> v2 = {"ab","ef","azy"}, v4;
	std::vector<std::vector<double>> v3;

	std::cout << v1.size() << std::endl;
	std::cout << v2.size() << std::endl;
	std::cout << v3.size() << std::endl;

	afficherVecteur(v1);
	afficherVecteur(v2);

	v4 = v2;
	v4[0] = "aaaa";
	afficherVecteur(v2);
	afficherVecteur(v4);

	vecteurPair (v1, 6);
	vecteurPairImpair(v1);
	afficherVecteur(v1);

	return 0;
}