#ifndef INDEXUNDERFLOW_H
#define INDEXUNDERFLOW_H
#include "IndexException.hpp"

class IndexUnderFlow: public IndexException
{
    public:
        IndexUnderFlow(int i): IndexException("Index Underflow: "+std::to_string(i)){}

    protected:

    private:
};

#endif // INDEXUNDERFLOW_H
