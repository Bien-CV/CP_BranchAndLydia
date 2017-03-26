#include "Problem.h"
#include <stdio.h>
#include <stdlib.h>


void initQueenProblem(Problem* p,int newn ){
  p->d=newDomain(newn);
  p->n = newn;
  Constraint cl;
  Constraint cdm;
  Constraint cdd;
  p->c=malloc(sizeof(Constraint)*3*(p->n)*(p->n)-3*(p->n));
  int compte = 0;
  for(int i = 0;i<p->n;i++){
    for(int j=0;j<p->n;j++){
      if(i!=j){
        initConstraint(cl,0,0,i,j);
        initConstraint(cdm,i,j,i,j);
        initConstraint(cdd,-i,-j,i,j);
        (p->c)[compte]=cl;
        compte++;
        (p->c)[compte]=cdm;
        compte++;
        (p->c)[compte]=cdd;
        compte++;
      }
    }
  }
  p->m += compte;
}

Problem* newProblem(int newn){
	Problem* p=malloc(sizeof(Problem));
	initQueenProblem(p, newn);
	return p;
}

void destroyProblem(Problem * p){
    destroyDomain(p->d);
    free(p->c);
    free(p);
	return;
}

void afficherProblem(Problem p){
  afficherDomain(*(p.d));
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
    if(!validationContrainte(p.c[i],d)){
      printf("Contrainte pas bonne\n");
      //break;
      return false;
    }
  }
  return true;
}

bool verifCtes(Problem p, Domain d){
  for(int i=0;i<p.m;i++){
    if(!validationContrainte(p.c[i],d)){
      return false;
    }
  }
  return true;
}
