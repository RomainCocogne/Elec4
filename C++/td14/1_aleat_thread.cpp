
#include <thread>
#include <chrono>
#include <ctime>
#include <iostream>
#include <cstdlib>

void prodAlea (const int & pause) {
    const  int max = 300;
    const auto t_id = std::this_thread::get_id();
    std::srand(std::time(0));
    while(true) {
        std::this_thread::sleep_for(std::chrono::seconds(pause));
        std::cout << "[" << std::rand()%max << " - "
                  << t_id << "] "
                  << std::flush;
    }
}

int main() {
    std::thread t0(prodAlea, 1);
    std::thread t1(prodAlea, 2);
    std::thread t2(prodAlea, 3);
    
    t0.join();
    t1.join();
    t2.join();

    return EXIT_SUCCESS;
}