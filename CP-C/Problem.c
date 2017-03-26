#include "Problem.h"

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

void afficher(Problem p){
  afficher(p.D);
  return;
}

bool isSolution(Domain D){
  for(int i=0;i<n;i++){
    if(Lenght(D.LDomain[i])>1){
      cout<<"taille pas bonne"<<endl;
      return false;
    }
  }
  for(int i=0;i<m;i++){
    if(!C[i].verif(F)){
      cout<<"contrainte pas bonne"<<endl;
      //break;
      return false;
    }
  }
  return true;
}

bool verifCte(Domain F){

}
