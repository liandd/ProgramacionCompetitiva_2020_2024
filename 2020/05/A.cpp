#include <bits/stdc++.h>
using namespace std;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	int n;
	cin>>n;
	vector<long> tiempo(n);
	vector<long> distancia(n);
	
	for(int i = 0; i < n; i++){
		cin>>tiempo[i]>>distancia[i];
	}
	
	long salida = 0, actual = 0;
	for(int i = 1; i < n; i++){
		actual = (distancia[i] - distancia[i - 1]) / (tiempo[i] - tiempo[i - 1]);
		salida = max(salida, actual);
	}
	
	cout<<salida<<'\n';
	return 0;
}
