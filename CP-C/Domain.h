
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
void destroyDomainContent(Domain d);
void initDomain(Domain* d, int newn);
void afficherDomain(Domain d);
bool isEmpty(Domain d);
int smallestDom(Domain d);
int biggestDom(Domain d);
Domain * newDomain(int newn);
void initEmptyDomain(Domain* d, int nbOfVariables);
Domain * newEmptyDomain(int nbOfVariables);
void addToDomain(Domain * d,int value,int variable);
#endif
