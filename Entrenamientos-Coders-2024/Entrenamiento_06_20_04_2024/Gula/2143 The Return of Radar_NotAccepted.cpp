#include <bits/stdc++.h>

using namespace std;

int main(){
	
	int t,n, res;
	
	while(cin>>t && t!=0){
		for(int i=0; i<t; i++){
			cin>>n;
			
						
			if(n==0){
				res=0;
			}else if(n==2){
				res=2;	
			}else if(n%2!=0){
				n=n-1;
				res=n*2+1;
			}else{
				res=n*2+2;
			}
			
			cout<<res<<"\n";
		}
	}
	
	
	
}