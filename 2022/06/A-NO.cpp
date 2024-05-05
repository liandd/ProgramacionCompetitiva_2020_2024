#include <bits/stdc++.h>
using namespace std;

int main(){

	string s;
	int prom=0;
	int div=0;
	char resp;
	int suma=0;
	
	getline(cin,s);
	
	for(int i=0 ; i<s.length();i++){
		
		if(s[i]!=00){
			suma= suma + s[i];
			div++;
		}
		
	}
	
	prom = suma/div;
	resp=prom;
	cout<<resp<<"\n";

	return 0;

}
