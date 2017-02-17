#ifndef DEF_DOMAIN
#define DEF_DOMAIN

#include <iostream>
#include <list>
#include <list>

using namespace std;

class Domain
{
    public:

    Domain();
    Domain(int newn);
    void afficher();
    bool isEmpty();
    int smallestDom();

    //private:

    int n;
    list<int> *LDomain;
};

#endif
