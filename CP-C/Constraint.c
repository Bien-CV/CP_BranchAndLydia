#ifndef DEF_CONSTRAINT
#define DEF_CONSTRAINT

#include <iostream>
#include <string>
#include "Domain.h"

class Constraint
{
    public:
    Constraint();
    Constraint(int newi, int newj, int newxi, int newxj);
    bool verif(Domain F);

    private:
      int i;
      int j;
      int xi;
      int xj;
};

#endif
