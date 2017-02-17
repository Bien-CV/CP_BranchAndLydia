#include <iostream>
#include <string>
#include <set>
#include <list>
#include "Problem.h"

using namespace std;

Domain BranchAndPrune(Problem P){
  list<Domain> L;
  int xi,v;
  Domain E,F,G;
  list<int> dxi,reset;
  L.push_front(P.getD());
  int t=0;
  while(t<10&&!L.empty()){
    t++;
    cout << L.size()<<endl;
    E = L.front();
    L.pop_front();
    if(L.size()>0){cout<<"L[0] : "<<endl;L.front().afficher();}
    F = E;//P.prune(E);
    cout<<"F : "<<endl;
    E.afficher();
    if(F.isEmpty()||!P.verifCte(F)){
      Domain F,E;
      cout<<"ça va pas là"<<endl;
    }
    else{
      if(P.isSolution(F)){
        return F;
      }
      else{
        xi = F.smallestDom();
        dxi = F.LDomain[xi];
        for (list<int>::iterator it=dxi.end(); it!=dxi.begin(); --it){//for each v dans dxi
            v = *it;
            G = F;
            cout<<"V = "<<v<<endl;
            G.LDomain[xi]=reset;
            G.LDomain[xi].push_front(v);
            G.afficher();
            L.push_front(G);
        }
      }
    }
  }
  return F;
}

int main(){
  Problem P(4);
  P.afficher();
  BranchAndPrune(P);

    return 0;
}
