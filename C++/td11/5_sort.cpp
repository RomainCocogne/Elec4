#include <vector>
#include <iostream>
#include <iomanip>
#include <string>
#include <algorithm>


template<typename T>
void println(const T &v) {
    std::for_each(v.begin(), v.end(), [] (auto x) {
                                        std::cout << std::setw(4) << x; });
    std::cout << std::endl;
}

int main(int argc, char const *argv[]) {
    std::vector<int> v = {10, 1, -2, 13, -4};
    println(v);
    std::sort(v.begin(), v.end(),
                    [] (int a, int b) -> bool { return a > b; });
    println(v);
    return 0;
}
