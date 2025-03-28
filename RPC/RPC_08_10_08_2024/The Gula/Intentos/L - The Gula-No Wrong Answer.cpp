#include <bits/stdc++.h>

using namespace std;
int main(){
	string pal;
	
	cin>>pal;
	
	int tam= pal.length();
	
	int n;
	
	
	
	
	if( tam >= 1 && tam <= 32){
		n=1;	
	}
	
	if(tam > 32 && tam <= 64){
		n=2;
	}
	
	if(tam > 64 && tam <= 128){
		n=3;
	}
	
	if(tam > 128 && tam <= 256){
		n=4;
	}
	
	if(tam > 256 && tam <= 512){
		n=5;
	}
	
	
	string res;
	for(int i=0; i<n; i++){
		res+="long ";
	}
	
	cout<<res<<"\b\n";
	
	
	
	
	return 0;
}