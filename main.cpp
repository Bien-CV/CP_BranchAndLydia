#include <iostream>
#include <set>
#include <list>

using namespace std;

class Ctype{
	public:
};

set<int> prune(set<int> E, Ctype C){
	return E;
}

bool isASolution(set<int> F){
	return true;
}

class Problem{
	public:
	
};

set<int> branchAndPrune(int X[],Ctype C, list< set<int> > D)
//avec X variables, C contraintes et D domaines des variables
{
	list< set<int> > L = D;
	set<int> E;
	set<int> F;
	while ( !L.empty() )
	{
		E = L.front();
		L.pop_front();
		F = prune(E,C);
		if ( F.empty()){
			F.clear(); //reinitialiser F
		}else
		{
			if ( isASolution(F)){
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
