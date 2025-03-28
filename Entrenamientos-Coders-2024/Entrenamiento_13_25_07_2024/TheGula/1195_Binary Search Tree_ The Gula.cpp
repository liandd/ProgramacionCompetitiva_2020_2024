#include <bits/stdc++.h>

using namespace std;

struct nodo {
	int dato;
	nodo *der;
	nodo *izq;
};

nodo *arbol = NULL;

nodo *crearNodo(int n) {
	nodo *nuevo_nodo = new nodo();

	nuevo_nodo->dato=n;
	nuevo_nodo->der=NULL;
	nuevo_nodo->izq=NULL;


	return nuevo_nodo;
}

void insertarNodo(nodo *&arbol, int n) {
	if(arbol==NULL) {
		nodo *nuevo_nodo = crearNodo(n);
		arbol = nuevo_nodo;
	} else {
		int valorRaiz = arbol->dato;
		if(n<valorRaiz) {
			insertarNodo(arbol->izq,n);
		} else {
			insertarNodo(arbol->der,n);
		}
	}
}

void mostrarArbol(nodo *arbol, int cont){
	if(arbol == NULL){
		return;
	}else{
		mostrarArbol(arbol->der,cont+1);
		for(int i=0; i<cont; i++){
			cout<<" ";
		}
		cout<<arbol->dato<<"\n";
		mostrarArbol(arbol->izq,cont+1);
	}
	
}

void preOrden(nodo *arbol) {
	cout<<" "<<arbol->dato;
	if (arbol->izq != NULL) {
		preOrden(arbol->izq);
	}
	if (arbol->der != NULL) {
		preOrden(arbol->der);
	}
}
void inOrden(nodo *arbol) {	
	if (arbol->izq != NULL) {
		inOrden(arbol->izq);
	}
	cout<<" "<<arbol->dato;
	if (arbol->der != NULL) {
		inOrden(arbol->der);
	}
}
void postOrden(nodo *arbol) {	
	if (arbol->izq != NULL) {
		postOrden(arbol->izq);
	}
	if (arbol->der != NULL) {
		postOrden(arbol->der);
	}
	cout<<" "<<arbol->dato;
}

int main() {
	int n=0;

	scanf("%d",&n);
	for(int i=0; i<n; i++) {
		int x=0;
		scanf("%d",&x);
		while(x--) {
			int a=0;
			scanf("%d",&a);
			insertarNodo(arbol,a);
		}
		cout<<"Case "<<i+1<<":\n";
		cout<<"Pre.:";
		preOrden(arbol);
		cout<<"\n";
		cout<<"In..:";
		inOrden(arbol);
		cout<<"\n";
		cout<<"Post:";
		postOrden(arbol);
		cout<<"\n\n";
		arbol=NULL;
	}
}