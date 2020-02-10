#pragma once
#include <map>
#include <string>
#include <iostream>
#include <sstream>

class Dico{
 private:
    std::map<std::string, int> m;

    std::string toString() {
        std::ostringstream s;
        for (auto mot: this->m)
            s << mot.first << ": " << mot.second << std::endl;
        return s.str();
    }
 protected:
 public:
    void inserer(std::string elt) {
        if (m.find(elt) != m.end()) {
            m[elt]++;
        } else {
            m[elt] = 1;
        }
    }

    friend std::ostream &operator << (std::ostream &f, Dico d){
        return f << d.toString();
    }
};
