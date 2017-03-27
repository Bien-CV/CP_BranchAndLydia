#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

#include "pile.h"

/*************************************************************************/

void Push(pile **p, int Val)
{
        pile *element = malloc(sizeof(pile));
        if(!element) exit(EXIT_FAILURE);     /* Si l'allocation a échouée. */
        element->valeur = Val;
        element->prec = *p;
        *p = element;       /* Le pointeur pointe sur le dernier élément. */
}
/*************************************************************************/

int Pop(pile **p)
{
        int Val;
        pile *tmp;
        if(!*p) return -1;     /* Retourne -1 si la pile est vide. */
        tmp = (*p)->prec;
        Val = (*p)->valeur;
        free(*p);
        *p = tmp;       /* Le pointeur pointe sur le dernier élément. */
        return Val;     /* Retourne la valeur soutirée de la pile. */
}

/*************************************************************************/

void Clear(pile **p)
{
        pile *tmp;
        while(*p)
          {
             tmp = (*p)->prec;
             free(*p);
             *p = tmp;
          }
}
/*************************************************************************/

int Length(pile *p)
{
        int n=0;
        while(p)
        {
            n++;
            p = p->prec;
        }
        return n;
}

/*************************************************************************/

void View(pile *p)
{
	pile *tmp=p;
        while(tmp)
          {
             printf("%3d ",tmp->valeur);
             tmp = tmp->prec;
          }
}

pile ** newMatricePile(int newn){
	pile** newMatrix=malloc(sizeof(pile*)*newn);
	return (newMatrix);
}
pile ** newEmptyMatricePile(){
	pile** newMatrix=malloc(sizeof(pile*)*MAX_NB_OF_VARIABLES_EMPTY_DOMAIN);
	return (newMatrix);
}

void afficheMatricePile(pile** mat,int size){
	assert(size >= 0 );
	for(int i = 0;i<size;i++){
		if(mat[i]!=NULL) {
			printf("ligne %4d : ",i+1);
			View(mat[i]);
			printf("\n");
		}else{
			printf("ligne %4d : Vide\n",i);
		}
	}
	return;
}

void clearMatricePile(pile** mat,int size){
	for(int i = 0;i<size;i++){
		if(mat[i]!=NULL) {
			Clear(&(mat[i]));
		}
	}
	return;
}


void findAndDelete(int e,pile** teteDePile){
	pile* tamponLecture=*teteDePile;

	if (tamponLecture->valeur==e){
		if ( tamponLecture->prec == NULL ){
			*teteDePile=NULL;
			free(tamponLecture);
			return;

		}else{
			*teteDePile=tamponLecture->prec;
			free(tamponLecture);
			return;

		}

	}else{
		while(tamponLecture->prec){//Tant qu'il y a un noeud precedent
			if( (tamponLecture->prec->valeur )==e){
				pile* tmp = tamponLecture->prec->prec;
				free(tamponLecture->prec);

				tamponLecture->prec=tmp;
				return;
			}
		tamponLecture=tamponLecture->prec;
		}
	}
	return;
}

int find(int e,pile** teteDePile){

	pile** tamponLecture=teteDePile;
	int i=0;
	while(*tamponLecture){
		if((*tamponLecture)->valeur==e){
			return i;
		}
		(*tamponLecture)=(*tamponLecture)->prec;
		i++;
	}

	return -1;
}

int isInStack(int e,pile** teteDePile){

	if (find(e,teteDePile)==-1)
		return 0;
	return 1;
}

int getValuePile(pile * p,int col){ //si on dépasse, retourne la derniere valeur
  int ind = 0;
  pile* tmp = p;
  while(ind!=col&&ind<Length(p)-1){
    ind++;
    tmp = tmp->prec;
  }
  //printf("%d\n", (p)->valeur);
  return tmp->valeur;
}
