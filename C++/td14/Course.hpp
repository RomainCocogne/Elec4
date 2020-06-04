#pragma once

#include <vector>
#include <string>
#include <sstream>
#include <mutex>
#include "Thread.hpp"


class Cheval: public Thread{
 private:
    std::string name;
    int distance;
    int rang;
    int *arrivee;
 public:
    Cheval(std::string n, int d, int *a): name{n}, distance{d}, rang{0}, arrivee{a}{}

    int getrang(){ return rang;}
    std::string getname(){ return name;}

    void run () override {
        static std::mutex m;
        const  int max = 500;
        std::srand(std::time(0));
        while(distance > 0) {
            std::this_thread::sleep_for(std::chrono::milliseconds(std::rand()%max));
            distance--;
        }
        m.lock();
        rang = *arrivee;
        (*arrivee)++;
        m.unlock();
    }
};

class Course{
 private:
    std::vector<Cheval*> chevaux;
    int arrivee;

 public:
    Course(std::vector<std::string> c_name): arrivee{1} {
        for (auto cheval_name: c_name){
            chevaux.push_back(new Cheval(cheval_name, 10, &arrivee));
        }
    }

    void run () {
        for (auto c: chevaux) {
            c->start();
        }
        for (auto c: chevaux) {
            c->join();
        }
    }

    std::string donnerLesResultats() {
        std::ostringstream ss;
        for (auto c: chevaux) {
            ss << c->getrang() << " " << c->getname() << std::endl;
        }
        return ss.str();
    }

};