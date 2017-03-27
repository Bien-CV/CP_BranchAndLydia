#ifndef DEF_CONSTRAINT
#define DEF_CONSTRAINT

#include "Domain.h"

typedef struct Constraint
{
  int i;//fixe
  int j;//fixe
  int xi;
  int xj;
}Constraint;

void initConstraint(Constraint* c, int newi, int newj, int newxi, int newxj);
void afficherConstraint(Constraint c);
bool validationContrainte(Constraint c, Domain d);
bool validerUNEContrainte(Constraint c, int xi, int xj);


#endif
