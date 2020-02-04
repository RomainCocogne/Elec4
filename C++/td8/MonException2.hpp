#ifndef MONEXCEPTION2_H
#define MONEXCEPTION2_H
#include "MonException1.hpp"

class MonException2: public MonException1
{
    public:
        MonException2() {}
        const  char *what()const noexcept{
            return "Mon exception 2";
        }

    protected:

    private:
};

#endif // MONEXCEPTION2_H
