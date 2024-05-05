#include <bits/stdc++.h>
using namespace std;

struct rest{
	string nombre;
	bool dispo;
};

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	int n, suma_dispo = 0;
	cin>>n;
	vector<rest> menus(n);
	
	for(int casos = 0; casos < n; casos++){
		int cant;
		bool sopa = false, pan = false;
		cin>>cant;
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		getline(cin, menus[casos].nombre);
		for(int i = 0; i < cant; i++){
			string aux;
			getline(cin, aux);
			if(aux == "pea soup") sopa = true;
			if(aux == "pancakes") pan = true;
		}
		if(pan && sopa){
			suma_dispo += 1;
			menus[casos].dispo = true;
		}else{
			menus[casos].dispo = false;
		} 
	}
	if(suma_dispo == n){
		cout<<"Anywhere is fine I guess"<<'\n';
	}else{
		for(int i = 0; i < n; i++){
			if(menus[i].dispo){
				cout<<menus[i].nombre<<'\n';
				return 0;
			}
		}
		cout<<"Anywhere is fine I guess"<<'\n';
	}
	
	return 0;
}
