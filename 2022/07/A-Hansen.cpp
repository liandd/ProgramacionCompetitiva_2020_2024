#include <iostream>
#include <bits/stdc++.h>

using namespace std;

    
int main(){

int n=0;
int t=0;
vector <int> arreglo;
int saldo=0;
int acum=0;
int contador=0;
cin>>n;

for(int i=0;i<n;i++ ){
	
	int a;
	cin>>a;
	arreglo.push_back(a);
	if(a<0){
		if(saldo< (a*-1)){
			acum=acum+((a*-1)-saldo);
			saldo=0;
			
		}else{
			saldo=saldo+a;
		}
	}
	else{
		saldo=saldo+a;
	}
}

cout<<acum<<endl;
/*
	if(arreglo[0]<0){
		contador=acum+(arreglo[0]*-1);
	}
	
	for(int i=1;i<arreglo.size();i++){
		
		
		/*
		t=arreglo[i-1]+arreglo[i];
		if(t<0){
		acum=(t*-1);
		contador+=acum;
		
		}
		*/
		
		
		
		
	}
	
	
	
	

