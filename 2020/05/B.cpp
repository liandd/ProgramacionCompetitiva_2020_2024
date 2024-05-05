#include <bits/stdc++.h>
using namespace std;

int n;
int matriz[25][25];

bool solve(){
	int suma = 0, verificar;
	for(int i = 0; i < n; i++){
		suma = 0;
		string f = "";
		verificar = 0;
		for(int j = 0; j < n; j++){
			suma += matriz[i][j];
			if(matriz[i][j] == 0){
				verificar = 0;
				f += "0";
				if(f.length() >= 3) return false;
			}else{
				verificar += 1;
				f = "";
				if(verificar >= 3) return false;
			}
		}
		if(suma > (n/2)) return false;
		
	}
	
	for(int i = 0; i < n; i++){
		suma = 0;
		string f = "";
		verificar = 0;
		for(int j = 0; j < n; j++){
			suma += matriz[j][i];
			if(matriz[j][i] == 0){
				verificar = 0;
				f += "0";
				if(f.length() >= 3) return false;
			}else{
				verificar += 1;
				f = "";
				if(verificar >= 3) return false;
			}
		}
		if(suma > (n/2)) return false;
	}
	
	return true;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin>>n;
	matriz[n][n];
	bool salida = false;
	
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			char aux;
			cin>>aux;
			matriz[i][j] = (aux == 'B' ? 0 : 1);
		}
	}
	
	salida = solve();
	cout<< (salida ? 1 : 0)<<'\n';
	return 0;
}
