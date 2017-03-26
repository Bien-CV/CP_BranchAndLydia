
#ifndef CGI_DOMAIN_H
#define CGI_DOMAIN_H

#include <stdbool.h>
#include "pile.h"

typedef struct Domain
{
    pile** LDomain;
    int n;
} Domain;

void initDomain(Domain d, int newn);
void afficherDomain(Domain d);
bool isEmpty(Domain d);
int smallestDom(Domain d);
int biggestDom(Domain d);
int** getLDomain(Domain d);
void setLDomain(Domain d,int* s, int i);
#endif
