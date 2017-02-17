#ifndef DEF_PROBLEM
#define DEF_PROBLEM

#include <iostream>
#include <string>
#include <set>
#include "Domain.h"
#include "Constraint.h"

class Problem
{
    public:

    Problem(int newn);
    ~Problem();
    void afficher();
    bool isSolution(Domain F);
    Domain getD();
    bool verifCte(Domain F);

    private:

    int n;
    int m;
    Domain *D;
    Constraint *C;
};

#endif
