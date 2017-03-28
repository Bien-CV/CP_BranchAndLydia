
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include "Domain.h"
#include "pile.h"
/*
Un domaine est représenté par un ensemble ordonné d’entiers. Ce type est muni au moins
des opérations suivantes outre la création : copie, accès aux valeurs, suppression d’une
valeur aux bornes, suppression d’une valeur quelconque

*/

Domain* copyDomain(Domain* d){
	Domain * cpy = malloc(sizeof(Domain));
	return cpy;
}

int deleteValue(Domain* d,int variable, int e){
	findAndDelete(e,&(d->LDomain)[variable]); 
	return 1;
}

int getValue(Domain* d,int variable, int col){
	return getValuePile(d->LDomain[variable],col);
}

int deleteMin(Domain* d,int variable){
	return 0;
}
int deleteMax(Domain* d,int variable){

	return 0;
}

void initDomain(Domain* d, int newn){

  pile ** liste = newMatricePile(newn);

  if(!liste) exit(EXIT_FAILURE);

  for(int i=0;i<newn;i++){
	  for(int j = 0;j<newn;j++){
		Push(&liste[i],j);
	  }
	}

  d->n = newn;
  //printf("Initialisation, n = %d\n",d->n);
  d->LDomain = liste;

  return;
}

void initEmptyDomain(Domain* d, int nbOfVariables){

  pile ** liste = newEmptyMatricePile(nbOfVariables);

  if(!liste) exit(EXIT_FAILURE);

  d->n = nbOfVariables;

  d->LDomain = liste;

  return;
}

void addToDomain(Domain * d,int value,int variable){

  if( variable < d->n ){
	  Push(&(d->LDomain[variable]),value);
	}
  return;
}


Domain * newDomain(int newn){
	Domain* newDomain=malloc(sizeof(Domain));
	initDomain(newDomain, newn);
	return newDomain;
}

Domain * newEmptyDomain(int nbOfVariables){
	Domain* newDomain=malloc(sizeof(Domain));
	initEmptyDomain(newDomain,nbOfVariables);
	return newDomain;
}

void destroyDomain(Domain* d){
	clearMatricePile(d->LDomain,d->n);
	return;
}
void destroyDomainContent(Domain d){
	clearMatricePile(d.LDomain,d.n);
	free(d.LDomain);
	return;
}
void afficherDomain(Domain d){
  printf("afficherDomain: n = %d\n",d.n);
  assert(d.LDomain!=NULL);
  assert(d.n >= 0);
  afficheMatricePile(d.LDomain,d.n);
	return;
}

bool isEmpty(Domain d){
  bool empty = false;
  for(int i=0;i<d.n;i++){
    empty = empty && (Length(d.LDomain[i])==0);
    //printf("%d",Length(d.LDomain[i])==0);
  }
	return empty;
}

int smallestDom(Domain d){
  int smallest = Length(d.LDomain[0]);
  int indsmallest = 0;
  int encours = 0;
  for(int i=0;i<d.n;i++){
	  afficherDomain(d);
	  printf("I = %d \n",i);
    encours = Length(d.LDomain[i]);
    printf("BYE !\n");
    if((encours<smallest)||(smallest==1)){
      smallest=encours;
      indsmallest = i;
    }
  }
	return indsmallest;
}

int biggestDom(Domain d){
  int biggest = Length(d.LDomain[0]);
  int indbiggest = 0;
  int encours = 0;
  for(int i=0;i<d.n;i++){
    encours = Length(d.LDomain[i]);
    if(encours>biggest){
      biggest=encours;
      indbiggest = i;
    }
  }
	return indbiggest;
}
