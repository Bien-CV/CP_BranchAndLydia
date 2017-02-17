#include <iostream>
#include "Domain.h"


using namespace std;

Domain::Domain(){
}

Domain::Domain(int newn) : n(newn)
{
  /*for(int i = 0;i<n;i++){
    for(int j=0;j<n;j++){
      D[i].insert(j);
    }
  }*/
  n=newn;
  cout<<"creer domaine : n = "<<n<<endl;
  list<int> s;
  for(int i=0;i<n;i++)
    s.push_back(i);
  LDomain = new list<int>[n];
  for(int i=0;i<n;i++)
    LDomain[i]=s;
  //D.push_front(s);
}

void Domain::afficher()
{
  cout<<"afficher domaine : n = "<< n <<endl;
  for(int i=0;i<n;i++){
    cout<<i<<" : ";
    for (list<int>::iterator it=LDomain[i].begin(); it!=LDomain[i].end(); ++it)
        std::cout << " "<< *it;
    std::cout<< '\n';
  }

}

bool Domain::isEmpty(){
  bool empty = false;
  for(int i=0;i<n;i++){
    empty = empty && (LDomain[i].size()==0); //&& strict car meme si on a qu'un domaine de vide, c'est pas bon
  }
  return empty;
}

int Domain::smallestDom(){
  int smallest = 0;
  for(int i=0;i<n;i++){ //si plus petit que l'actuel ou mauvaise initialisation et que >1 (sinon ça sert à rien un noeud)
    if((LDomain[i].size()<LDomain[smallest].size() || LDomain[smallest].size()<=1)&&LDomain[i].size()>1){
      smallest = i;
    }
  }
  return smallest;
}

list<int>* Domain::getLDomain(){
  return LDomain;
}

void Domain::setLDomain(list<int> s,int i){
  LDomain[i]=s;
}
