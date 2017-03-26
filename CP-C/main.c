

#include <stdlib.h>
#include <stdio.h>

#include "Constraint.h"
#include "Problem.h"
#include "Domain.h"
#include "pile.h"
#include "pile_Dom.h"


void test_Domain(){
	int newn=5;
	Domain * d=newDomain(newn);
		
	afficherDomain(*d);
	destroyDomain(d);

}
void test_pile(){
	pile ** p=malloc(sizeof(pile *));
	for(int i=0;i<3000;i++)
		Push(p,i);
	 Clear(p);
	 free(p);
}
void test_Problem(){
	int newn=5;
	Domain * d=newDomain(newn);
	
	Problem* p=newProblem(10);
	
	afficherProblem(*p);
	isSolution(*d,*p);
	verifCtes(*p,*d);
	
	destroyDomain(d);
	destroyProblemContent(p);
	free(p);
}
void test_pile_Dom(){
	
	Problem*  P=newProblem(10);
	
	pile_Dom** L=NULL;
	L=malloc(sizeof(pile_Dom*));
	Push_dom(L,*(P->d));
	
	Domain pd;
	Pop_dom(L,&pd);
	afficherDomain(pd);
	destroyDomainContent(pd);
	destroyDomain(&pd);
	//free(pd);
    //affichage manuel spécifique
    //afficherDomain(L->dom);
    //affichage de toute la pile
    View_dom(*L);
    
    Clear_dom(L);
    
    destroyProblemContent(P);
    free(P);
    free(L);
    
    
}

void testEmptyDomain(){
	
	int nbVariablesMaximum=10;
	Domain * d=newEmptyDomain(nbVariablesMaximum);
	
	addToDomain(d,5,0);
	addToDomain(d,3541,0);
	addToDomain(d,6,1);
	
	afficherDomain(*d);
	
	int tab[]={124,12,10,9,8,7,6,5,4,3,2,1,0,-50};
	int sizeTab=14;
	//addLineToDomain ne devrait pas être utilisé dans un tableau n'ayant pas le nombre de variable maximum nécessaire
	addLineToDomain(d,tab,sizeTab);
	
	afficherDomain(*d);
	
	destroyDomainContent(*d);
	free(d);
}
Problem* newProblem(int newn);
void initQueenProblem(Problem* p,int newn );
void afficherProblem(Problem p);
bool isSolution(Domain d, Problem p);
bool verifCtes(Problem p, Domain d);
/*
Domain BranchAndPrune(Problem P){
  pile_Dom L;
  int xi,v;
  Domain E,F,G;
  pile dxi,reset;
  Push_dom(L,P.D);
  int t=0;
  while(t<10&&Length_dom(L)>0){
    Domain E,F,G;
    t++;
    printf("Taille de L : %d\n",Length_dom(L));
    F = Pop_dom(L);
    printf("Taille de F : %d\n",)
    afficherDomain(F);

    if(isEmpty(F)||!verifCtes(P,F)){
      printf("vide ou verif pas les contraintes\n");
    }

    else{
      xi = smallestDom(F);
      printf("xi = %d\n",xi);
      dxi = F.LDomain[xi];

      while(dxi!=NULL){
        pile temp;
        Push(&temp,dxi.valeur);
        F.LDomain[xi] = temp;
        dxi = dxi.prec;
        Clear(temp);
      }
    }

  }
}
*/
/*
int resoudreReines(int taille){
	
  Problem p;
  initProblem(P,taille);
  afficherProblem(P);
  Domain sol = BranchAndPrune(P);
  printf("Solution :\n");
  afficherDomain(sol);
  
}
*/
int main()
{
		//test_pile();
		//test_Domain();
		//test_Problem();
		//test_pile_Dom();
		testEmptyDomain();
      /*  pile *MaPile = NULL;

        Push(&MaPile, 10);
        View(MaPile);
        Length(MaPile);
        Pop(&MaPile);
        Clear(&MaPile);

        Domain test;// = NULL;
        initDomain(test,4);
        afficherDomain(test);
        printf("%d\n",isEmpty(test));
        //test.n = 4;
        printf("%d\n",test.n);

        Constraint c;
        initConstraint(c,1,2,3,4);
         */
        //printf("xi %d %d\n",c.xi,c.xj);
        


#ifdef _WIN32
        system("PAUSE");  /* Pour la console Windows. */
#endif
        
        
        return 0;
}
