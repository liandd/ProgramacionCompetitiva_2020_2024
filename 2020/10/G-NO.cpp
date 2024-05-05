#include <bits/stdc++.h>
using namespace std;

class videos{
	public:
	int cantidad;
	vector<int> tiempos;
	videos(int a, vector<int> b){
		cantidad = a;
		tiempos = b;
	}
};

bool operator<(const videos& v1,const videos& v2){
	for(int i = v1.cantidad - 1, j = v2.cantidad - 1; i >= 0 || j >= 0; i--, j--){
		if(v1.tiempos[i] != v2.tiempos[j]) return v1.tiempos[i] > v2.tiempos[j];
	}
	return true;
}

int main(){
	int n;
	cin>>n;
	priority_queue<videos> pq;

	for(int i = 0; i < n; i++){
		int k; cin>>k;
		vector<int> aux;
		for(int j = 0; j < k; j++){
			int t; cin>>t;
			aux.push_back(t);
		}
		pq.push(videos(k, aux));
	}

	int salida = 0;
	for(int i = 0; i < n; i++){
		videos aux = pq.top();
		pq.pop();
		for(int j = 0; j < aux.cantidad; j++){
			if(aux.tiempos[j] > salida){
				salida = aux.tiempos[j];
				break;
			}
		}
	}
	
	cout<< (salida + 1) <<endl;
	return 0;
}


