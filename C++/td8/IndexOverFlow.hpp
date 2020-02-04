#ifndef INDEXOVERFLOW_H
#define INDEXOVERFLOW_H
#include "IndexException.hpp"

class IndexOverFlow: public IndexException
{
    public:
        IndexOverFlow(int i): IndexException("Index Overflow: "+std::to_string(i)){}

    protected:

    private:
};

#endif // INDEXOVERFLOW_H
