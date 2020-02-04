#ifndef PILE_H
#define PILE_H
#include <forward_list>
#include <iostream>
#include <sstream>

template <typename T> class Pile
{
    public:
        Pile() {}

        void empiler(const T &e){
            l.push_front(e);
        }
        void depiler(){
            l.pop_front();
        }
        const T sommet() const {
          return l.front();
        }
        bool estVide()const {
            return this->l.empty();
        }

        friend std::ostream &operator << (std::ostream &f, Pile<T> &p){
            return f << p.toString();
        }

    protected:
        std::forward_list<T> l;
    private:
        std::string toString(){
            std::ostringstream s;
            s << "top ";
            for(auto e: l) s << e << std::endl;
            return s.str();
        }
};

#endif // PILE_H
