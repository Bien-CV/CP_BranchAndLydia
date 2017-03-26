#ifndef DEF_PROBLEM
#define DEF_PROBLEM

#include <stdbool.h>
#include "Domain.h"
#include "Constraint.h"

typedef struct Problem
{
    int n;
    int m;
    Domain D;
    Constraint *C;
}Problem;

void initProblem(Problem p,int newn );
void afficherProblem(Problem p);
bool isSolution(Domain F, Problem p);
Domain getD();
bool verifCte(Domain F);

#endif
