#include <bits/stdc++.h>
using namespace std;

int main() {
	string nin;
	cin>>nin;
	int ninos[nin.length()];
	int cont=0;
	for(int i=0; i<nin.length(); i++) {
		ninos[i]=nin.at(i)-1; // Se resta 0 para convertir el char a numero
	}

	for(int i=0; i<nin.length()-1; i++) {
		for(int j=0; j<nin.length()-1; j++) {
			if(ninos[j]>ninos[j+1]) {
				swap(ninos[j],ninos[j+1]);
				cont++;
			}
		}
	}
	cout<<cont<<"\n";
	//Hay que quitar un for
	return 0;
}