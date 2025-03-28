#include <bits/stdc++.h>

using namespace std;
int main(){

	string  pal;
	cin>>pal;
	bool ban=true;;
	int cont=0;
	
	for(int i=0; i<pal.size(); i++){
		if(pal[i]=='('){
			cont++;
		}else if(pal[i]==')'){
			cont--;
			if(cont<0){
				ban=false;
				break;
			}
		}
	}
	
	if(cont==0 && ban==true){
		cout<<"correct\n";
	}else{
		cout<<"incorrect\n";
	}
	
	
	return 0;
	
}