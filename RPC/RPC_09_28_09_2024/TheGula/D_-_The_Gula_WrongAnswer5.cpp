#include <bits/stdc++.h>

using namespace std;

int main() {

	int n=0, m=0;

	cin>>n>>m;
	vector <long long> puntos(n);

	for(int i=0; i<n; i++) {
		cin>>puntos[i];
	}

	long long mayorPuntaje=0;
	long long aux=0;

	if(m==1) {
		for(int i=0; i<n; i++) {
			mayorPuntaje=max(mayorPuntaje, puntos[i]);
		}
	} else if(n==1){
		mayorPuntaje=0;
	}else {
		for(int i=0; i<n; i++) {
			aux=0;
			int limiteFor=min(n-1,(m-1)+i);
			// cout<<puntos[limiteFor]<<" - Puntos\n";
			aux=puntos[limiteFor];
			// cout<<aux<<" - Salida del for\n";

			aux=aux-puntos[i];
			// cout<<aux<<" - Resta\n";
			mayorPuntaje=max(aux, mayorPuntaje);
		}
	}

	cout<<mayorPuntaje<<"\n";
	return 0;
}