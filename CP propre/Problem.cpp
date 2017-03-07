
#include "Problem.h"
#define VERBOSE_PROBLEM (0)
using namespace std;


Problem::Problem(int newn) : n(newn){
  if VERBOSE_PROBLEM cout<<"creer pb"<<endl;
  n=newn;
  D = new Domain(n);
  if VERBOSE_PROBLEM cout<<"fin de creation du pb : n = "<<n<<endl;

  //ajout des contraintes (reines)
  C = new Constraint[3*n*n-3*n];
  int compte = 0;
  for(int i = 0;i<n;i++){
    for(int j=0;j<n;j++){
      if(i!=j){
        Constraint cl(0,0,i,j);
        Constraint cdm(i,j,i,j);
        Constraint cdd(-i,-j,i,j);
        C[compte]=cl;
        compte++;
        C[compte]=cdm;
        compte++;
        C[compte]=cdd;
        compte++;
      }
    }
  }
  m=compte;

}

void Problem::afficher(){
  D->afficher();
}

Problem::~Problem(){
}

Domain Problem::getD(){
  return *D;
}

bool Problem::isSolution(Domain F){
  for(int i=0;i<n;i++){
    if(F.getLDomain()[i].size()>1){
      cout<<"taille pas bonne"<<endl;
      return false;
    }
  }
  for(int i=0;i<m;i++){
    if(!C[i].verif(F)){
      cout<<"contrainte pas bonne"<<endl;
      return false;
    }
  }
  return true;
}

bool Problem::verifCte(Domain F){
  for(int i=0;i<m;i++){
    if(!C[i].verif(F)){
      cout<<"contrainte pas bonne "<<i<<endl;
      return false;
    }
  }
  return true;
}

/*Domain prune(Domain E){//forward checking -> pas utilisé pour la part 1
  Domain F = E;
  //pour toutes les contraintes :
  for(int i=0;i<m;i++){
    if(E[C[i].xi].size()==1 && E[C[i].xj].size()>1){
      E[C[i].xj].remove(C[i].xi+C[i].i-C[i].j);
    }
    if(E[C[i].xi].size()>1 && E[C[i].xj].size()==1){
      E[C[i].xi].remove(C[i].xj+C[i].j-C[i].i);
    }

  }
  //si xi n'a qu'une solution dans E et xj plusieurs
    //E[xj].remove(xi+i-j)
  //de meme pour xj
  return F;
}*/
