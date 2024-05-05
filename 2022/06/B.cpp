#include <bits/stdc++.h>
using namespace std;

int main(){

	string cadena,resp;
	int pos;
	
	cin>>cadena;

    for(int i=cadena.length()-1;i>=0;i--){
		if(cadena[i]=='a'||cadena[i]=='e'||cadena[i]=='i'||cadena[i]=='o'||cadena[i]=='u'){
			pos=i;
			break;
		}	
    }
    
	for(int i=0;i<cadena.length();i++){
		if(i==pos){
			resp+=cadena[i];
			resp+="ntry";
			break;
		}
		resp+=cadena[i];
	}
	
	cout<<resp<<"\n";
	return 0;
}
