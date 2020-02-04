#ifndef MONEXCEPTION_H
#define MONEXCEPTION_H
#include <iostream>

class MonException
{
    public:
        MonException() {}
        friend std::ostream& operator << (std::ostream &f,MonException &me){
            f << "MonException";
            return f;
		}


    protected:

    private:
};

#endif // MONEXCEPTION_H
