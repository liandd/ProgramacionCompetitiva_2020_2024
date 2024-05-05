#include <bits/stdc++.h>
using namespace std;

int main(){
	int n; cin>>n;
	
	int elecA = 0, elecB = 0, vA = 0, vB = 0;
	for(int i = 0; i < n; i++){
		int elec = 0, auxA = 0, auxB = 0;
		cin>>elec;
		cin>>auxA; vA += auxA;
		cin>>auxB; vB += auxB;
		if(auxA > auxB){
			elecA += elec;
		}else if(auxB > auxA){
			elecB += elec;
		}
	}
	if((elecA > elecB) && (vA > vB)) cout<<1<<endl;
	else if( (elecB > elecA) && (vB > vA)) cout<<2<<endl;
	else cout<<0<<endl;
	return 0;
}
