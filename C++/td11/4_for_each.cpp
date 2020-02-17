#include <vector>
#include <iostream>
#include <iomanip>
#include <string>
#include <algorithm>

class Sum {
 private:
    int som;
 public:
    Sum(): som(0) {}
    void operator()(int s) {
        som += s;
    }
    friend std::ostream &operator<<(std::ostream &f, const Sum &s) {
        return f << s.som;
    }
};

template<typename T>
void println(const T &v) {
    std::for_each(v.begin(), v.end(), [] (auto x) {
                                        std::cout << std::setw(4) << x; });
    std::cout << std::endl;
}

int main(int argc, char const *argv[]) {
    std::vector<int> v = {10, 1, -2, 13, -4};
    println(v);
    std::for_each(v.begin(), v.end(),
                    [] (int &n) { n <<= 1; });
    println(v);
    auto s = std::for_each(v.begin(), v.end(),
                    Sum());
    std::cout << s << std::endl;

    return 0;
}
