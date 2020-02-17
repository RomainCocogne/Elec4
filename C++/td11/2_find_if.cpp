#include <algorithm>
#include <iostream>
#include <vector>
#include <iomanip>


int main(int argc, char const *argv[]) {
    std::vector<int> v = {10, 1, -2, 13, -4};
    auto pos = v.begin();
    do {
        pos = std::find_if(pos, v.end(), [](auto x) -> bool {
                                                    return x < 0; });
        if (pos != v.end()) {
            std::cout << *pos << std::endl;
            ++pos;
        }
    } while (pos != v.end());

    pos = v.begin();
    do {
        pos = std::find_if(pos, v.end(), [](auto x) -> bool {
                                                    return (x&1) == 0; });
        if (pos != v.end()) {
            std::cout << *pos << std::endl;
            ++pos;
        }
    } while (pos != v.end());
    return 0;
}
