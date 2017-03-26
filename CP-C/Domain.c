
#include <stdlib.h>
#include <stdio.h>
#include "Domain.h"
/*
Un domaine est représenté par un ensemble ordonné d’entiers. Ce type est muni au moins
des opérations suivantes outre la création : copie, accès aux valeurs, suppression d’une
valeur aux bornes, suppression d’une valeur quelconque 

*/


void initDomain(Domain* d, int newn){

  pile ** liste = newMatricePile(newn);

  if(!liste) exit(EXIT_FAILURE);
  
  for(int i=0;i<newn;i++){
	  for(int j = 0;j<newn;j++){
		Push(&liste[i],j);
	  }
	}
  
  d->n = newn;
  printf("Initialisation, n = %d\n",d->n);
  d->LDomain = liste;

  return;
}

Domain * newDomain(int newn){
	Domain* newDomain=malloc(sizeof(Domain));
	initDomain(newDomain, newn);
	return newDomain;
}

void destroyDomain(Domain* d){
	clearMatricePile(d->LDomain,d->n);
	free(d->LDomain);
	free(d);
	return;
}
void afficherDomain(Domain d){
  printf("afficherDomain: n = %d\n",d.n);
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
    encours = Length(d.LDomain[i]);
    if(encours<smallest){
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
