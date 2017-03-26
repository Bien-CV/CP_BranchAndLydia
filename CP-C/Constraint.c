#include <stdlib.h>
#include "Constraint.h"

void initConstraint(Constraint c, int newi, int newj, int newxi, int newxj){

  c.i = newi;
  c.j = newj;
  c.xi = newxi;
  c.xj = newxj;
}

bool validationContrainte(Constraint c, Domain d){
  if(Length(d.LDomain[smallestDom(d)])<1){
    return false;
  }
  if(Length(d.LDomain[biggestDom(d)])>1){
    return true;
  }
  
  int expr1 = d.LDomain[c.xi]->valeur + c.i;
  int expr2 = d.LDomain[c.xj]->valeur + c.j;
  return ( expr1 != expr2 );
}
