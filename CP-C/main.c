

#include <stdlib.h>
#include <stdio.h>
#define NOMBRE_MAXIMUM_ITERATIONS 100000
#define MAX_NB_OF_TIME_RECORDINGS 3000
#define AFFICHAGE_STANDARD if(false)
#define TIMER_ON if(true)
#define FWD_CHKING 0
#define BORN_CONS 1
#define ARC_CONS 2
    
#include "Constraint.h"
#include "Problem.h"
#include "Domain.h"
#include "pile.h"
#include "pile_Dom.h"
#include <time.h>
#include <string.h>

typedef struct timeRecord{
	char* name;
	int id;
	clock_t start;
	clock_t stop;
	int pruneType;
	int sizeFactor;
}timeRecord;

typedef struct timeLog{
	timeRecord* records;
	int nbOfRecords;
}timeLog;

//Renvoie l'index du timer créé
int newTimer(timeLog* log, char* name, int pruneType, int sizeFactor){
	int usableIndex=log->nbOfRecords;
	log->records[usableIndex].start = clock();
	log->records[usableIndex].stop = 0;
	log->records[usableIndex].name=calloc(strlen(name)+1,sizeof(char)*2);
	log->records[usableIndex].pruneType=pruneType;
	log->records[usableIndex].sizeFactor=sizeFactor;
	strcpy(log->records[usableIndex].name,name);
	log->records[usableIndex].id = usableIndex;
	log->nbOfRecords=usableIndex+1;
	return usableIndex;
}
void stopTimer(timeLog* log,int index){
	log->records[index].stop=clock()-log->records[index].start;
}

void printSolution(Domain E){
	return;
}
Domain Prune_ForwardChecking(Problem *P,Domain D){ //et qui marche in your face

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

	return D;
}

Domain Prune_ArcConsistency(Problem* P,Domain D){ // rq : AC1

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



int BranchAndPrune(int taille,int typeOfPruning){
  int xi;
  //Domain* E = newDomain(taille);//,F,G;
  pile* dxi;

	Problem* P = newProblem(taille);
	pile_Dom** L = calloc(1,sizeof(pile_Dom*));
	
	Push_dom(L,*(P->d));
	Length_dom(*L);
  int t=0;
  while((t<NOMBRE_MAXIMUM_ITERATIONS) && (Length_dom(*L)>0) ){
    //Domain E,F,G;
   
    t++;
    AFFICHAGE_STANDARD printf("Taille de L : %d\n",Length_dom(*L));
    Domain F;
    Domain E ;
    Pop_dom(L,&F);
    //afficherDomain(F);
    
    if ( typeOfPruning == FWD_CHKING ) E = Prune_ForwardChecking(P,F);
    if ( typeOfPruning == BORN_CONS ) E = Prune_BornConsistency(P,F);
    if ( typeOfPruning == ARC_CONS ) E = Prune_ArcConsistency(P,F);
    AFFICHAGE_STANDARD afficherDomain(E);
    /*if(!isEmpty(E))
      afficherDomain(E);*/

    //printf("%d\n", verifCtes(*P,E));
    if(isEmpty(E)||!verifCtes(*P,E)){
      AFFICHAGE_STANDARD printf("vide ou verif pas les contraintes\n");
    }

    else{
      if(isSolution(E,*P)){
        AFFICHAGE_STANDARD printf("Une solution a été trouvée.\n");
        printSolution(E);
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
    
    //View_dom(*L);

  }


  Clear_dom(L);
  destroyProblemContent(P);
  free(P);
  free(L);
  return 0;
}
void showLogCSV(timeLog* log){
	printf("type de pruning;taille de l'échiquier;nom du timer;durée en temps CPU;\n");
	
	for (int i=0;i< (log->nbOfRecords );i++){
		if ( (log->records)[i].pruneType == FWD_CHKING ) printf("FWD_CHKING;");
		if ( (log->records)[i].pruneType == BORN_CONS ) printf("BORN_CONS;");
		if ( (log->records)[i].pruneType == ARC_CONS ) printf("ARC_CONS;");
		printf("%d;",(log->records)[i].sizeFactor);
		printf("%s;%lu;\n",(log->records)[i].name,(log->records)[i].stop);
	}
	printf("\n");
}

void initLog(timeLog* log){
	log->records=calloc(MAX_NB_OF_TIME_RECORDINGS,sizeof(timeRecord));
	log->nbOfRecords=0;
}

timeLog* newLog(){
	timeLog* newLog=calloc(1,sizeof(timeLog));
	initLog(newLog);
	return newLog;
}
void incrementer(int * pi){
	*pi=*pi+1;
}

void destroyLog(timeLog* log){
	for (int i=0;i< (log->nbOfRecords );i++){
		free((log->records)[i].name);
	}
	free(log->records);
}

int main()
{
  timeLog* log=newLog();
  int maxNameLen = 200;
  char* buffer=calloc(maxNameLen,sizeof(char));
  int timerIndex;
  int maxNbOfIterations = 20;
  
  for(int i=1;i<maxNbOfIterations;incrementer(&i)){
	TIMER_ON snprintf ( buffer, maxNameLen, "BranchAndPrune(%d,FWD_CHKING)",i);  
	TIMER_ON timerIndex= newTimer(log,buffer,FWD_CHKING, i);
	BranchAndPrune(i,FWD_CHKING);
	TIMER_ON stopTimer(log, timerIndex);  
	AFFICHAGE_STANDARD printf("Done i = %d\n",i);
  }
  for(int i=1;i<maxNbOfIterations;incrementer(&i)){
	TIMER_ON snprintf ( buffer, maxNameLen, "BranchAndPrune(%d,BORN_CONS)",i);  
	TIMER_ON timerIndex= newTimer(log,buffer,BORN_CONS,i);
	BranchAndPrune(i,BORN_CONS);
	TIMER_ON stopTimer(log, timerIndex);  
	AFFICHAGE_STANDARD printf("Done i = %d\n",i);
  }
  for(int i=1;i<maxNbOfIterations;incrementer(&i)){
	TIMER_ON snprintf ( buffer, maxNameLen, "BranchAndPrune(%d,ARC_CONS)",i);  
	TIMER_ON timerIndex= newTimer(log,buffer,ARC_CONS,i);
	BranchAndPrune(i,ARC_CONS);
	TIMER_ON stopTimer(log, timerIndex);  
	AFFICHAGE_STANDARD printf("Done i = %d\n",i);
  }
  
  
  TIMER_ON showLogCSV(log);
  
  destroyLog(log);
  free(log);
  free(buffer);
  
  #ifdef _WIN32
        system("PAUSE");  /* Pour la console Windows. */
#endif
  return 0;
}
