#include <bits/stdc++.h>
using namespace std;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	int dias;
	cin>>dias;
	vector<int> temp(dias); 
	
	for(int i = 0; i < dias; i++) cin>>temp[i];
	
	int maxD = 0, maxT = 41;
	for(int i = 1; i < dias - 1; i++){
		int aux = max(temp[i - 1], temp[i + 1]);
		
		if(aux < maxT){
			maxT = aux;
			maxD = i;
		}
	}
	
	cout<<maxD<<' '<<maxT<<'\n';
	return 0;
}
