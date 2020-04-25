#include <functional>
#include <iostream>
#include <ctime>


int main(int argc, char const *argv[]) {
    auto creer_generateur = [] (int n =1000) {
        std::srand(std::time(0));
        return [n] () {return std::rand()%n;};
    };
    std::function <int()> g1 = creer_generateur(10);
    auto g2 = creer_generateur();
    std::cout  << g1() << std::endl;
    std::cout  << g1() << std::endl;
    std::cout  << g2() << std::endl;
    std::cout  << g1() << std::endl;
    std::cout  << g2() << std::endl;
    return 0;
}
