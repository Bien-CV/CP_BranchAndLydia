#include <iostream>
#include <string>
#include <set>
#include <list>
#include <vector>
#include <stack>
#include "Problem.h"

using namespace std;

Domain BranchAndPrune(Problem P){
  stack<Domain> L;
  int xi,v;
  Domain E,F,G;
  list<int> dxi,reset;
  L.push(P.getD());
  int t=0;
  while(t<10&&!L.empty()){
    Domain E,F,G;
    t++;
    cout <<"Taille L :"<< L.size()<<endl;
    F = L.top(); //normalement E
    //L.pop();
    /*for (vector<Domain>::iterator it=L.begin(); it!=L.end(); ++it){
      cout<<*it.afficher()<<endl;
    }*/
  //  if(L.size()>0){cout<<"L[0] : "<<endl;L.front().afficher();}
  //  F = E;//P.prune(E);
    //cout<<"F : "<<endl;
    F.afficher();
    if(F.isEmpty()||!P.verifCte(F)){
      //delete &F;
      cout<<"ça va pas là"<<endl;
    }
    else{
      if(P.isSolution(F)){ //verifie taille domaines + ctes
        return F;
      }
      else{
        xi = F.smallestDom();
        dxi = F.getLDomain()[xi];
        for (list<int>::iterator it=dxi.end(); it!=dxi.begin(); --it){//for each v dans dxi
            //list<int>::iterator it = dxi.end();
            v = *it-1;
            Domain G = F;
            //cout<<"V = "<<v<<endl;
            list<int> reset;
            reset.push_back(v);
            G.getLDomain()[xi]=reset;
          //  G.afficher();
            L.push(G); //ERREUR A LA CON LA DESSUS

          /*
            //L.front().afficher();
            if(L.size()>1){
              E=L.back();
              L.pop_back();
              cout<<"affichage E + L.back"<<endl;
              E.afficher();
              L.back().afficher();
              L.push_back(E);
            }*/
          }
      }
    }
  }
  return F;
}

int main(){
  Problem P(4);
  P.afficher();
  Domain Sol = BranchAndPrune(P);
  cout<<"Solution : "<<endl;
    return 0;
}
