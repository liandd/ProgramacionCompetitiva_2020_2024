#include <bits/stdc++.h>

using namespace std;

int main(){
	
	int tam;
	cin>>tam;
	vector <string> palabras(tam);
	
	for(int i=0; i<tam; i++){	
		cin>>palabras[i];	
	}
	
	for(int i=0; i<tam; i++){
		 if(palabras[i].size()==3 && 
		 (palabras[i][0]=='O' || palabras[i][0]=='U' ) &&
		 (palabras[i][1]=='B' || palabras[i][1]=='R' )  ){
		 	string a="",b="",c="I", res;
		 	a=palabras[i][0];
		 	b=palabras[i][1];
		 	
		 	res=a+b+c;
		 	palabras[i]=res;
		 }
	}
	
	for(int i=0; i<tam; i++){
		cout<<palabras[i];
		if(i!=tam-1){
			cout<<" ";
		}
	}
	
	cout<<"\n";
	
	return 0;
}