#ifndef MANDELVEC_H
#define MANDELVEC_H
#include "vec.h"

class MandelVec
{
    public:
        MandelVec();
        MandelVec(int ni, Vec* vect);
        int getN();
        Vec getVec();
    private:
        int n;
        Vec vec;
};

#endif // MANDELVEC_H
