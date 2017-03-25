#ifndef DEF_CONSTRAINT
#define DEF_CONSTRAINT

#include <stdbool.h>
#include "Domain.h"

typedef struct Constraint
{
    public:
    Constraint();
    initConstraint(int newi, int newj, int newxi, int newxj);
    bool verif(Domain F);

    private:
      int i;
      int j;
      int xi;
      int xj;
};

#endif
