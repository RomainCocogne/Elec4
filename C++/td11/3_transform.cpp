#include <string>
#include <algorithm>
#include <vector>
#include <iostream>
#include <iomanip>


template<typename T>
void println(const T &v) {
    std::for_each(v.begin(), v.end(), [] (auto x) {
                                        std::cout << std::setw(4) << x; });
    std::cout << std::endl;
}

int main(int argc, char const *argv[]) {
    std::string s = "hello";
    std::transform(s.begin(), s.end(), s.begin(), [] (const unsigned char &c) {
                                                    return std::toupper(c); });
    std::cout << s << std::endl;
    s = "hello";
    std::transform(s.begin(), s.begin()+1, s.begin(),
                    [] (const unsigned char &c) { return std::toupper(c); });
    std::cout << s << std::endl;

    std::vector<int> v = {10, 1, -2, 13, -4};
    println(v);
    std::transform(v.begin(), v.end(), v.begin(),
                    [] (int n) { return n <<= 1; });
    println(v);
    std::for_each(v.begin(), v.end(),
                    [] (int &n) { return n <<= 1; });
    println(v);
    return 0;
}
