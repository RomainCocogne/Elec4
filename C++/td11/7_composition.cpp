#include <functional>
#include <iostream>

template <typename T, typename H, typename I>
std::function <T(H)>
compose(std::function <I(H)> f, std::function <T(I)> g) {
    return[&f, &g] (H x) { return g(f(x)); };
}

int main(int argc, char const *argv[]) {
    auto gof = compose<double, int*, int>( [] (int *t) {return *t;}, [] (double x) {return x*x;});
    int t[] = {3, 4, 5};
    std::cout  << gof(t) << std::endl;
    return 0;
}
