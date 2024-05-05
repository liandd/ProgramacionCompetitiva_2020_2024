#include <bits/stdc++.h>
using namespace std;

int main(){
	long k, n, exit = 0, j;
	cin>>k>>n;
	string salida = ""; 
	vector<long> arreglo(k); 
	for(long i = 0; i < k; i ++) cin>>arreglo[i];
	
	for(long i = 0; i < k - n; i++){
		vector<bool> referencia(n, false); 
		string f = "";
		for(j = i, exit = 0; j < k; j++){
			if(referencia[arreglo[j] - 1] == false){
				referencia[arreglo[j] - 1] = true;
				char aux = arreglo[j] + '0'; 	
				f += aux;
				exit++;
				if(exit == n) break;
			}
		}
		if(salida == ""){
			salida = f;
		}else if(f.length() == n && salida != ""){
			salida = min(salida, f);
		}
	}
	
	for(long i = 0; i < n; i++) cout<<salida[i]<<' ';
	cout<<'\n';
	return 0;
}
