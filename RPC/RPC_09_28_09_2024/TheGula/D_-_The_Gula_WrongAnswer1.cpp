#include <bits/stdc++.h>

using namespace std;

int main() {

	int n=0, m=0;

	scanf("%d%d", &n,&m);
	vector <int> puntos(n);

	for(int i=0; i<n; i++) {
		scanf("%d", &puntos[i]);
	}

	int mayorPuntaje=0;
	int aux=0;
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

	printf("%d\n", mayorPuntaje);
	
	return 0;
}