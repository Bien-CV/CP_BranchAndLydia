#include <iostream>
#include <string>
#include <set>
#include <list>
#include <vector>
#include <stack>
#include <assert.h>
#include "Problem.h"
#include <climits>

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

void domainCreationTests(){
	int step = INT_MAX / 300;
	for( int i=INT_MIN; i<INT_MAX; i=i+step ){
	Domain* tDomain;
	tDomain = new Domain(i);
	assert( tDomain->isEmpty() );
	}
	
	
}

void domainEveryLineIsIndependantTest(){
	int sizeOfDomain=100;
	Domain tDomain(sizeOfDomain);
	list<int> * tLDomain = tDomain.getLDomain();
	for (int i= 0 ; i< sizeOfDomain-1 ; i++){	
		assert(tLDomain[i] != tLDomain[i+1]);
	}
}

void domainClassTests(){
	cout<<"TEST: Domain"<<endl;
	domainCreationTests();
	domainEveryLineIsIndependantTest();
	Domain tDomain;
	
	return;
}
	
void constraintClassTests(){
	
	cout<<"TEST: Constraint"<<endl;
	Constraint tConstraint;
	
	return;
}
	
void problemClassTests(){
	cout<<"TEST: Problem"<<endl;
	int initialNewN = 0;
	Problem tProblem(initialNewN);
	
	return;
}
	
void testSuite(){
	cout<<"Début de la suite de tests"<<endl;
	
	
	domainClassTests();
	
	constraintClassTests();
	
	problemClassTests();
	
	return;
}

void queen(){
  Problem P(4);
  P.afficher();
  Domain solution = BranchAndPrune(P);
  cout<<"Solution : "<<endl;
  solution.afficher();
}

int main(){
  
  //testSuite();
  queen();
  
  return 0;
}
