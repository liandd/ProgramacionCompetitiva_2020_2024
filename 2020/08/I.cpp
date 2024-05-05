#include <bits/stdc++.h>
using namespace std;

class med{
	public: 
	int prioridad, freq, tiempo;
	string name;
	med(int a, int b, int c, string d){
		prioridad = a;
		freq = b;
		tiempo = c;
		name = d;
	}
};

bool operator<(const med& n1, const med& n2) {
	bool dif_tiempo = n1.tiempo > n2.tiempo;
	bool prioridad_pastas = n1.prioridad > n2.prioridad;
	return (n1.tiempo == n2.tiempo ? prioridad_pastas : dif_tiempo);
}

int main() {
	int T, n, k, frecuencia_pasta;
	string nombre;
	scanf("%d", &T);
	while(T--){
		scanf("%d", &n);
		scanf("%d", &k);
		priority_queue<med> pastas;
		for(int i = 0; i < n; i++){
		    cin>>nombre;
		    scanf("%d", &frecuencia_pasta);
			pastas.push(med(i, frecuencia_pasta, frecuencia_pasta, nombre));
		}

		for(int i = 0; i < k; i++) {
			med aux = pastas.top();
			pastas.pop();
			printf("%d", aux.tiempo);
			cout<<" "<<aux.name<<endl;
			pastas.push(med(aux.prioridad, aux.freq, aux.tiempo + aux.freq, aux.name));
		}
	}
	return 0;
}