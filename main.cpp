#include <iostream>
#include <set>
#include <list>

using namespace std;

class Problem{
public:
	int n;
	int X[];
	set<int> D[]; //mon ensemble de domaine aura toujours une taille n
	//string type;
	bool isASolution(list< set<int> > F){
			/*int i,j;
			//F ne doit contenir qu'un seul elmt
			for(i=0;i<n;i++){
				if(F[i].size()>1){
					return false;
				}
			}
			//verif lignes
			for(i=0;i<n;i++){
				for(j=i;j<n;j++){
					if(F[i][1]==F[j][1]){
						return false;
					}
				}
			}
			//verif colonnes -> implicite à la declaration
			//verif diagonnales montantes
			for(i=0;i<n;i++){
				for(j=0;j<n;j++){
					if(F[i][1]+i==F[j][1]+j){
						return false;
					}
				}
			}
			//verif diagonales descendantes
			for(i=0;i<n;i++){
				for(j=0;j<n;j++){
					if(F[i][0]-i==F[j][0]-j){
						return false;
					}
				}
			}*/
		//F.get(0);
		return true;
	}

	list< set<int> > prune(list< set<int> > F, set <int> E){
		return F;
	}

};

list< set<int> > branchAndPrune(Problem P)
//avec X variables, C contraintes et D domaines des variables
{
	set<int> L[P.n] = P.D;
	set<int> E;
	list< set<int> > F;
	while ( !L.empty() )
	{
		E = L.front();
		L.pop_front();
		F = P.prune(F,E);
		if ( F.empty()){
			F.clear(); //reinitialiser F
		}else
		{
			if ( P.isASolution(F)){
				return F; //renvoyer F
			}else
			{
				//~ xi>-variable with smallest domain in F
				//~ let dxi be the domain of xi in F
				//for(each v in dxi)
				//{
					//~ G<-F
					//~ set the domain of xi to {v} in G
					//~ push G in L
				//}
			}
		}
	}
}


int main(){
	cout<<"Hello Lydia.\n"<<endl;
	return 0;
}
