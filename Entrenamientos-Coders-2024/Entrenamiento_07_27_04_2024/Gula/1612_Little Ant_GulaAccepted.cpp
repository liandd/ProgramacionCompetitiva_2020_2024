#include <bits/stdc++.h>

using namespace std;

int main(){
	int n=0;
	long long x=0, res=0;
	cin>>n;
	while(n--){
		cin>>x;
		
		if(x&1){ //impar
		res=x/2+1;	
		}else{
		 res=x/2;	
		}
		
		cout<<res<<"\n";
	}
}