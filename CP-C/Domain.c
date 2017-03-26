
#include <stdlib.h>
#include <stdio.h>
#include "Domain.h"

void initDomain(Domain d, int newn){

  pile ** liste = NULL;
  liste = malloc(newn*sizeof(Domain));

  if(!liste) exit(EXIT_FAILURE);
  for(int i = 0;i<newn;i++){
    Push(&liste[i],i);
  }
  d.n = newn;
  printf("Initialisation, n = %d\n",d.n);
  d.LDomain = liste;

  return;
}

void afficherDomain(Domain d){
  printf("Affichage, n = %d\n",d.n);
	return;
}

bool isEmpty(Domain d){
  bool empty = false;
  for(int i=0;i<d.n;i++){
    empty = empty && (Length(d.LDomain[i])==0);
    printf("%d",Length(d.LDomain[i])==0);
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
