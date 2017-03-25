#ifndef DEF_DOMAIN
#define DEF_DOMAIN

#include <stdbool.h>

typedef struct Domain
{
    int** LDomain;
    int n;
};

void initDomain(Domain d, int newn);
void afficherDomain(Domain d);
bool isEmpty(Domain d);
int smallestDom(Domain d);
int** getLDomain(Domain d);
void setLDomain(Domain d,int* s, int i);
#endif
