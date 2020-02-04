#ifndef INDEXEXCEPTION_HPP
#define INDEXEXCEPTION_HPP

#include <string>

class IndexException : public std::exception
{
    public:
        IndexException(const std::string m): msg(m) {}
        const  char *what()const noexcept{
            return msg.c_str();
        }

    protected:
        std::string msg;
    private:
};

#endif // INDEXEXCEPTION_HPP
