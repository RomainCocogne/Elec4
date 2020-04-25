#include <functional>
#include <iostream>

int main(int argc, char const *argv[]) {
    int n = 10;
    std::function <int(int)> f = [&n] (int x) {return n*x; };
    std::cout  << f(3)  << std::endl;
    return 0;
}
