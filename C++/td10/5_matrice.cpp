#include <iostream>
#include "Matrice.hpp"

int main(int argc, char const *argv[]) {
    const int M = 2;
    const int N = 3;

    Matrice<M, N, int> m;
    m[1][1] = 3;
    std::cout << m[1][1] << std::endl;

    for (auto i = m.begin(); i != m.end(); ++i) {
        std::cout << *i << " " << std::endl;
    }
    return 0;
}
