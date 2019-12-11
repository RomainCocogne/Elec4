#include <vector>
#include <cstdlib>
#include <iostream>
#include <ctime>

auto initMatrice (int m, int n){

	std::srand(std::time(NULL));

	std::vector<std::vector<double>> mat = std::vector<std::vector<double>>(n);

	for (int c = 0; c < n; c++){
		for (int l = 0; l < m; ++l)
			mat[c].push_back( std::rand()*100 );
	}
	return mat;
}

void afficherMatrice( auto m){
	for (std::vector<double> x : m)
	{
		for (double y : x)
			std::cout << y << '\t';
		std::cout << std::endl;
	}
}

int main(int argc, char const *argv[])
{
	auto mat = initMatrice(3,4);
	afficherMatrice(mat);
	return 0;
}