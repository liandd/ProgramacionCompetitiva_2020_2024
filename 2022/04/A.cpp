#include <bits/stdc++.h>

using namespace std;

int main(){
	
	string cadena;
	
	vector <int> abc (28,0);
	
	bool par=false;
	bool impar=false; 
	
	cin>>cadena;
	
	for(int i=0 ; i<cadena.length();i++) abc[cadena[i]-97]++;

	for(int i=0 ; i<abc.size();i++){
		
		if (abc[i] != 0){
			
			if (abc[i]% 2 == 0){
				par=true;
			}
			else{
				impar=true;
			}
			
		}
		
	}
	
	if(par && !impar){
		cout<<"0\n";
	}
	else if(!par && impar){
		cout<<"1\n";
	}
	else{
		cout<<"0/1\n";
	}
	
    return 0;
}








