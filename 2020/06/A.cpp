#include <bits/stdc++.h>
using namespace std;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	string animal;
	cin>>animal;
	int n;
	cin>>n;
	vector<string> lista(n);
	vector<string> seleccion;
	for(int i = 0; i < n; i++){
		cin>>lista[i];
		if(animal[animal.length() - 1] == lista[i][0]){
			seleccion.push_back(lista[i]);
		}
	}
	
	bool existe = seleccion.empty();
	for(int i = 0; i < seleccion.size(); i++){
		bool win = true;
		for(int j = 0; j < n; j++){
			if(seleccion[i] != lista[j] && seleccion[i][seleccion[i].length() - 1] == lista[j][0]){
				win = false;
				break;
			}
		}
		if(win){
	 		cout<<seleccion[i]<<"!\n";
	 		return 0;
	 	}
	}
	
	if(!existe){
		cout<<seleccion[0]<<'\n';
	}else{
		cout<<"?\n";
	}
	return 0;
}
