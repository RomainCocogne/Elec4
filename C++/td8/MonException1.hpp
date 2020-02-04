#ifndef MONEXCEPTION1_H
#define MONEXCEPTION1_H


class MonException1: public std::exception
{
    public:
        MonException1() {}
        const  char *what()const noexcept{
            return "Mon exception 1";
        }
    protected:

    private:
};

#endif // MONEXCEPTION1_H
