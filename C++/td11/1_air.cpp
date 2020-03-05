#include <cmath>
#include <iostream>
#include <cassert>
#include <functional>

/** Antecedent : a<=b et n>=1
*   Role : calcule l’aire de la  fonction  continue f
*   sur l’intervalle [a,b]
*   Algorithme : methode  des  rectangles, n est le nb de rectangles calcules
*/
double aire(double a, double b, int n, std::function<double(double)> f) {
    assert(a <= b);
    double largeurRect =(b-a)/n;
    double x = a+largeurRect/2;
    double aire = 0;
    for (int i=1; i <= n; i++, x += largeurRect)
        aire += largeurRect*f(x);
    return aire;
}

int main(int argc, char const *argv[]) {
    std::cout << "aire de cos(x) = " << aire(0, M_PI, 1000,
                                            [](auto x){ return cos(x); })
              << std::endl;
    return 0;
}
