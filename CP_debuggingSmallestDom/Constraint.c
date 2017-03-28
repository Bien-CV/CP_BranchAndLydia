#include <stdlib.h>
#include <stdio.h>
#include "Constraint.h"

void initConstraint(Constraint *c, int newi, int newj, int newxi, int newxj){

  c->i = newi;
  c->j = newj;
  c->xi = newxi;
  c->xj = newxj;
}

void afficherConstraint(Constraint c){
  printf("xi(%d) + i(%d) != xj(%d) + j(%d)\n", c.xi,c.i,c.xj,c.j);
}

bool validationContrainte(Constraint c, Domain d){
  if(Length(d.LDomain[smallestDom(d)])<1){
    return false;
  }
/*  if(Length(d.LDomain[biggestDom(d)])>1){
    return true;
  }*/
  if(Length(d.LDomain[c.xi])>1||Length(d.LDomain[c.xj])>1){
    return true;
  }
/*  printf("xi : %d,xj : %d,i : %d,j : %d,\n", c.xi,c.xj,c.i,c.j);
  printf("Verif vraiment\n");*/
  int expr1 = d.LDomain[c.xi]->valeur + c.i;
  int expr2 = d.LDomain[c.xj]->valeur + c.j;
  return ( expr1 != expr2 );
}

bool validerUNEContrainte(Constraint c, int xi, int xj){
  return xi + c.i != xj + c.j;
}
