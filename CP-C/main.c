

#include <stdlib.h>
#include <stdio.h>

#include "Constraint.h"
#include "Problem.h"
#include "Domain.h"
#include "pile.h"
#include "pile_Dom.h"

Domain Prune_ForwardChecking(Problem *P,Domain D){
  printf("\navant Pruning\n" );
  afficherDomain(D);
  //pour chaque variable dont il ne reste plus qu'une variable dans le domaine
  //pour chaque contrainte ou elle est présente, on propage sur l'autre (les autres)
  /*for(int i=0;i<P.n;i++){
    if(Length(P.D[i])==1){
      for(int j=0;j<P.m;j++){
        if(P.C[j].i==i){
          //D.LDomain[c.xi]->valeur + P.C[j].i != D.LDomain[c.xj]->valeur + P.C[j].j;
          //D[P.C[j].j] est privé de la valeur D.LDomain[c.xi]->valeur + P.C[j].i - D.LDomain[c.xj]->valeur
        }
        if(P.C[j].j==i){
          //D[P.C[j].i] est privé de la valeur D.LDomain[c.xj]->valeur + P.C[j].j - D.LDomain[c.xi]->valeur
        }
      }
    }
  }*/
  for(int i=0;i<P->m;i++){ //MIIIIEUX -> pour chaque contrainte on verifie si une et une seule valeur est fixée
    int lenxi = Length(D.LDomain[P->c[i].xi]);
    int lenxj = Length(D.LDomain[P->c[i].xj]);
    if(lenxi==1 && lenxj>1){
      deleteValue(&D,P->c[i].xj,(P->c[i].xi+P->c[i].i-P->c[i].j));
      printf("Variable :%d -valeur %d\n",P->c[i].xj,(P->c[i].xi+P->c[i].i-P->c[i].j));
    //  de D[P.C[i].xj] remove (P.C[i].xi+P.C[i].i-P.C[i].j);
    }


    if(lenxi>1 && lenxj==1){
      deleteValue(&D,P->c[i].xi,(P->c[i].xj+P->c[i].j-P->c[i].i));
      //de D[P.C[i].xi] remove (P.C[i].xj+P.C[i].j-P.C[i].i);
    }
  }
  printf("après Pruning\n" );
  afficherDomain(D);
  printf("\n" );
	return D;
}

/*bool Prune_ArcConsistency(Problem P,Domain D){ // rq : AC1
  bool term = false;
  while(!term){
    term = true;
    for(int i=0;i<P.m;i++){ //Pour chaque contrainte
      //on vérifie le domaine de i par rapport à j
      /D[i]-> domaine de la variable i
      Tant que !domaine vide
      on, verifie que valeur actuelle dans D[i] a un support dans D[j]
      ie qu'il existe dans D[j] au moins une valeur telle que
      xi+i != xj+j; -> avec xi la valeur dans D[i] qu'on cherche à verifier

      Si non on supprime la valeur actuelle de D[i]/


      //on vérifie le domaine de j par rapport à i
    }
  }
  return true;
}

bool Prune_BornConsistency(Problem P,Domain D){
  //pour chaque contrainte
  //on regarde le max et le min pour i et j -> théorique, on fait pas
  //si plus de deux valeurs pour i et j (dans le cas des reines) -> ok
}*/





int BranchAndPrune(int taille){
  int xi;
  //Domain* E = newDomain(taille);//,F,G;
  pile* dxi;

	Problem* P = newProblem(taille);
	pile_Dom** L = NULL;
  L=malloc(sizeof(pile_Dom*));

	Push_dom(L,*(P->d));

  int t=0;
  while(t<4&&Length_dom(*L)>0){
    //Domain E,F,G;
    t++;
    printf("Taille de L : %d\n",Length_dom(*L));
    Domain F;
    Domain E ;
    Pop_dom(L,&F);
    afficherDomain(F);
    E = Prune_ForwardChecking(P,F);
    afficherDomain(E);
  /*  if(!isEmpty(E))
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
              //copit de E
            }
          }
          //et on ajoute ça dans L
          Push_dom(L,(*tempD));
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
  //BranchAndPrune(4);
  pile ** P = newMatricePile(40);
  Push(P,4);
  Push(P,56);
  Push(P,556);
  Push(P,5426);
  Push(P,565244);
  afficheMatricePile(P,1);
  findAndDelete(4,P);
  findAndDelete(565244,P);
  afficheMatricePile(P,1);
  
  /*Domain* testD = newDomain(4);
  Constraint c ;
  initConstraint(&c,1,1,0,0);
  afficherDomain(*testD);*/

  #ifdef _WIN32
        system("PAUSE");  /* Pour la console Windows. */
#endif
  return 0;
}
