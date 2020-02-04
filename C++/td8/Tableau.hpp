#ifndef TABLEAU_H
#define TABLEAU_H

#include <iostream>
#include <sstream>
#include <initializer_list>

#include "IndexOverFlow.hpp"
#include "IndexUnderFlow.hpp"

template <int N,typename T>
class Tableau
{
    private:
    T elem[N];
    protected:

    public:
        Tableau(const std::initializer_list<T> &t) {
            int size = t.size();
            for (int i=0; i<size; i++)
                elem[i] = *(t.begin()+i);
        }

        Tableau(const T& v=T()) {
            for(int i=0 ; i<N ; i++)
                this->elem[i] = v;
        }
        Tableau (const Tableau<N,T>& t) {
            for(int i=0 ; i<N ; i++)
                this->elem[i] = t.elem[i];
        }

        Tableau<N,T> &operator=(const Tableau<N,T>& t) {
            for(int i=0 ; i<N ; i++)
                this->elem[i] = t.elem[i];
            return *this;
        }

        int longueur() const {return N;  }
        T &operator[] (int i) {
            if (i <0 )throw IndexUnderFlow(i);
            if (i>=N) throw IndexOverFlow(i);
            return this->elem[i];
        }

        const std::string toString() const {
            std::ostringstream s;
            s << "[ ";for (auto x : this->elem) s <<  x << "";
            s << "]";
            return s.str();
        }
        friend std::ostream& operator << (std::ostream& f, const Tableau<N,T> &t)  {
            return f << t.toString();
        }
};


#endif // TABLEAU_H



