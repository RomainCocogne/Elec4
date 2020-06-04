#pragma once

#include "Thread.hpp"
#include <mutex>


class Aleatoire: public Thread{
 private:
    int pause;

    void run () override {
        static std::mutex m;
        const  int max = 300;
        const auto t_id = std::this_thread::get_id();
        std::srand(std::time(0));
        while(true) {
            std::this_thread::sleep_for(std::chrono::seconds(pause));
            m.lock();
            std::cout << "[" << std::rand()%max << " - "
                      << t_id << "] "
                      << std::flush;
            m.unlock();
        }
    }
 public:
    Aleatoire(int p): pause{p} {}

};
