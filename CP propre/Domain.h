#ifndef DEF_DOMAIN
#define DEF_DOMAIN

#include <iostream>
#include <list>
#include <set>

using namespace std;

class Domain
{
    public:

    Domain();
    Domain(int newn);
    void afficher();
    bool isEmpty();
    int smallestDom();
    list<int> * getLDomain();
    void setLDomain(list<int> s, int i);
    list<int> *LDomain;
    
    private:

    int n;
    
};

#endif
