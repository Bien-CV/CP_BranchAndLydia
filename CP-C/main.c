

#include <stdlib.h>
#include <stdio.h>
#define NOMBRE_MAXIMUM_ITERATIONS 100000
#include "Constraint.h"
#include "Problem.h"
#include "Domain.h"
#include "pile.h"
#include "pile_Dom.h"

Domain Prune_ForwardChecking(Problem *P,Domain D){ //et qui marche in your face
  printf("\navant Pruning\n" );
  afficherDomain(D);

  for(int i=0;i<P->m;i++){ //pour chaque contrainte on verifie si une et une seule valeur est fixée
    int lenxi = Length(D.LDomain[P->c[i].xi]);
    int lenxj = Length(D.LDomain[P->c[i].xj]);

    if(lenxi==1 && lenxj>1){
      deleteValue(&D, P->c[i].xj, D.LDomain[P->c[i].xi]->valeur + P->c[i].i - P->c[i].j);
    }

    if(lenxi>1 && lenxj==1){ //pas besoin en fait, trop de contraintes deja
      deleteValue(&D, P->c[i].xi, D.LDomain[P->c[i].xj]->valeur + P->c[i].j - P->c[i].i);
      //printf("Variable :%d -valeur %d\n",P->c[i].xi,(P->c[i].xj+P->c[i].j-P->c[i].i));
      //de D[P.C[i].xi] remove (P.C[i].xj+P.C[i].j-P.C[i].i);
    }
  }
  printf("après Pruning\n" );
  afficherDomain(D);
  printf("\n" );
	return D;
}

Domain Prune_ArcConsistency(Problem* P,Domain D){ // rq : AC1
  printf("\navant Pruning\n" );
  afficherDomain(D);
  bool term = false;
  while(!term){
    term = true;
    for(int k=0;k<P->m;k++){ //Pour chaque contrainte k
      //on vérifie toutes les valeurs du domaine de i par rapport à celles de j
      for(int i=0;i<Length(D.LDomain[P->c[k].xi]);i++){
        int consistant = 0;
        int xi = getValuePile(D.LDomain[P->c[k].xi],i);
        for(int j=0;j<Length(D.LDomain[P->c[k].xj]);j++){
          int xj = getValuePile(D.LDomain[P->c[k].xj],j);
          if(validerUNEContrainte(P->c[k],xi,xj)){
            consistant = 1;
            break;
          }
        }

        if(!consistant){
          //term = false;
          deleteValue(&D,P->c[k].xi,xi); //on enlève de xi la valeur qui va pas
          //afficherDomain(D);
        }
      }
      /*on, verifie que valeur actuelle dans D[i] a un support dans D[j]
      ie qu'il existe dans D[j] au moins une valeur telle que
      xi+i != xj+j; -> avec xi la valeur dans D[i] qu'on cherche à verifier

      Si non on supprime la valeur actuelle de D[i]*/

      //on vérifie le domaine de j par rapport à i -> pas utile, contraintes inverses
    }
  }
  printf("après Pruning\n" );
  afficherDomain(D);
  printf("\n" );
  return D;
}

Domain Prune_BornConsistency(Problem* P,Domain D){
  //pour chaque contrainte
  for(int k=0;k<P->m;k++){
    int ximin = getValuePile(D.LDomain[P->c[k].xi],Length(D.LDomain[P->c[k].xi]));
  //on regarde le max et le min pour i et j -> théorique, on fait pas
  //si plus de deux valeurs pour i et j (dans le cas des reines) -> ok
  }
  return D;
}



int BranchAndPrune(int taille){
  int xi;
  //Domain* E = newDomain(taille);//,F,G;
  pile* dxi;

	Problem* P = newProblem(taille);
	pile_Dom** L = calloc(1,sizeof(pile_Dom*));
	
	Push_dom(L,*(P->d));
	Length_dom(*L);
  int t=0;
  while((t<NOMBRE_MAXIMUM_ITERATIONS) && (Length_dom(*L)>0) ){
	  printf("t=%d\n",t);
    //Domain E,F,G;
   
    t++;
    printf("Taille de L : %d\n",Length_dom(*L));
    Domain F;
    Domain E ;
    Pop_dom(L,&F);
    //afficherDomain(F);
    //E = Prune_ForwardChecking(P,F);
    //E = Prune_BornConsistency(P,F);
    E = Prune_ArcConsistency(P,F);
    afficherDomain(E);
    /*if(!isEmpty(E))
      afficherDomain(E);*/

    //printf("%d\n", verifCtes(*P,E));
    if(isEmpty(E)||!verifCtes(*P,E)){
      printf("vide ou verif pas les contraintes\n");
    }

    else{
      if(isSolution(E,*P)){
        printf("On a une solution !!\n");
        return 1;
      }
      else{
        xi = smallestDom(E);
        //printf("xi = %d\n",xi);
        dxi = E.LDomain[xi];

        while(dxi!=NULL){
          Domain * tempD = newEmptyDomain(taille);

          //on copie le domaine de E dans tempD
          for(int i=0;i<taille;i++){ //pour chaque variable
            if(i==xi) //soit c'est celle qu'on fixe
              addToDomain(tempD,dxi->valeur,i);
            else{ //soit on recopie E
              pile * next = E.LDomain[i];
              for(int j=0;j<Length(E.LDomain[i]);j++){

                addToDomain(tempD,((next)->valeur),i);

                next = next->prec;
              }
              
              //copie de E
            }
          }
          //et on ajoute ça dans L
          
          Push_dom(L,*tempD);
          
          /*afficherDomain(E);
          printf("tempD %d\n", tempD->LDomain[1]->valeur);
          afficherDomain(*tempD);*/
          dxi = dxi->prec;
          
        }
      }
    }
    /*printf("TADAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA----------debut-------------\n");
    View_dom(*L);
    printf("TADAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA----------fin-------------\n");*/

  }


/*  Clear_dom(L);
  destroyProblemContent(P);
  free(P);
  free(L);*/
  return 0;
}


int main()
{
  BranchAndPrune(4);
  /*pile ** P = newMatricePile(4);
  Push(P,4);
  Push(P,56);
  afficheMatricePile(P,1);
  printf("%d\n",getValuePile(P,0));
  afficheMatricePile(P,1);
  Domain* testD = newDomain(4);
  Constraint c ;
  initConstraint(&c,1,1,0,0);
  afficherDomain(*testD);*/

  #ifdef _WIN32
        system("PAUSE");  /* Pour la console Windows. */
#endif
  return 0;
}
