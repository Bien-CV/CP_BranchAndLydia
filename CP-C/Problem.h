#ifndef DEF_PROBLEM
#define DEF_PROBLEM

#include <stdbool.h>
#include "Domain.h"
#include "Constraint.h"

typedef struct Problem
{
    int n;
    int m;
    Domain *D;
    Constraint *C;
};
void initProblem(Problem p,int newn );
void afficher();
bool isSolution(Domain F);
Domain getD();
bool verifCte(Domain F);

#endif
