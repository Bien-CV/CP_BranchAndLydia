#include "Problem.h"
#include <stdio.h>


void initProblem(Problem p,int newn ){
  p.n = newn;
  Constraint cl;
  Constraint cdm;
  Constraint cdd;

  Constraint C[3*p.n*p.n-3*p.n];
  int compte = 0;
  for(int i = 0;i<p.n;i++){
    for(int j=0;j<p.n;j++){
      if(i!=j){
        initConstraint(cl,0,0,i,j);
        initConstraint(cdm,i,j,i,j);
        initConstraint(cdd,-i,-j,i,j);
        C[compte]=cl;
        compte++;
        C[compte]=cdm;
        compte++;
        C[compte]=cdd;
        compte++;
      }
    }
  }
  p.C = C;
  p.m = compte;

}

void afficherProblem(Problem p){
  afficherDomain(p.D);
  return;
}

bool isSolution(Domain d, Problem p){
  for(int i=0;i<d.n;i++){
    if(Length(d.LDomain[i])>1){
      printf("taille pas bonne\n");
      return false;
    }
  }
  for(int i=0;i<p.m;i++){
    if(!validationContrainte(p.C[i],d)){
      printf("Contrainte pas bonne\n");
      //break;
      return false;
    }
  }
  return true;
}

bool verifCtes(Problem p, Domain d){
  for(int i=0;i<p.m;i++){
    if(!validationContrainte(p.C[i],d)){
      return false;
    }
  }
  return true;
}
