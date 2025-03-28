#include <bits/stdc++.h>
using namespace std;

int main() {
	string ora="";
	getline(cin,ora);
	ora.erase(unique(ora.begin(), ora.end()), ora.end());
	int tam=ora.size();

	//cout<<ora<<"\n";

	int espacios=0;
	for(int i=0; i<tam; i++) {
		if(ora[i]==' ') {
			espacios++;
		}
	}
	cout<<espacios<<"\n";

	bool esMayus=false;

	int cont=0;
	for(int i=0; i<tam; i++) {

		if(islower(ora[i])) {

			if(!(esMayus && tolower(ora[i-1])==ora[i])) {
				cont++;
				esMayus=false;
				cout<<ora[i]<<" Minus "<<cont<<"\n";
			}
		} else if(isupper(ora[i])) {
			if(toupper(ora[i-1]) == ora[i]) {
				cont++;
			} else if(esMayus) {
				cont++;
			} else {
				cont+=2;
			}
			esMayus=true;
			cout<<ora[i]<<" Mayus "<<cont<<"\n";
		}
	}

	cout<<cont+espacios<<"\n";

	return 0;
}