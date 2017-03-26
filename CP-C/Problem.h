#ifndef DEF_PROBLEM
#define DEF_PROBLEM

#include <stdbool.h>
#include "Domain.h"
#include "Constraint.h"

typedef struct Problem
{
    int n;
    int m;
    Domain* d;
    Constraint *c;
}Problem;

Problem* newProblem(int newn);
void destroyProblemContent(Problem * p);
void initQueenProblem(Problem* p,int newn );
void afficherProblem(Problem p);
bool isSolution(Domain d, Problem p);
bool verifCtes(Problem p, Domain d);

#endif
