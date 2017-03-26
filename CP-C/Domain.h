
#ifndef CGI_DOMAIN_H
#define CGI_DOMAIN_H

#include <stdbool.h>
#include "pile.h"

typedef struct Domain
{
    pile** LDomain;
    int n;
} Domain;

void destroyDomain(Domain* d);
void initDomain(Domain* d, int newn);
void afficherDomain(Domain d);
bool isEmpty(Domain d);
int smallestDom(Domain d);
int biggestDom(Domain d);
Domain * newDomain(int newn);
//pile** getLDomain(Domain d);
//void setLDomain(Domain d,pile* s, int i);
#endif
