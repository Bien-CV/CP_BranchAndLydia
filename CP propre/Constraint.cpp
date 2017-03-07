
#include "Constraint.h"
#define VERBOSE_CONSTRAINT 0
 
using namespace std;

Constraint::Constraint(){

}

Constraint::Constraint(int newi, int newj, int newxi, int newxj){
  i = newi;
  j = newj;
  xi = newxi;
  xj = newxj;
}


bool Constraint::verif(Domain F){
  if(F.LDomain[xi].size()>1||F.LDomain[xj].size()>1){
    return true;
  }
/*  cout<<xi<<"  "<<i<<"  "<<endl;
  cout<<xj<<"  "<<j<<"  "<<endl;*/
  return (F.LDomain[xi].front()+i != F.LDomain[xj].front()+j);
}
