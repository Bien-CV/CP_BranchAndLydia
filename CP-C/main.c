

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
void test_Problem(){
	int newn=5;
	Domain * d=newDomain(newn);
	
	Problem* p=newProblem(10);
	
	afficherProblem(*p);
	isSolution(*d,*p);
	verifCtes(*p,*d);
	
	destroyDomain(d);
	destroyProblem(p);
}
void test_pile_Dom(){
	
	Problem* P=newProblem(10);
	
	pile_Dom* L;
	Push_dom(&L,*(P->d));
    afficherDomain(L->dom);
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
		//test_Domain();
		//test_Problem();
		test_pile_Dom();
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
