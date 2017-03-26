#ifndef DEF_CONSTRAINT
#define DEF_CONSTRAINT

#include "Domain.h"

typedef struct Constraint
{
  int i;
  int j;
  int xi;
  int xj;
}Constraint;

void initConstraint(Constraint c, int newi, int newj, int newxi, int newxj);
bool validationContrainte(Constraint c, Domain d);


#endif
