#include <bits/stdc++.h>
using namespace std;
int main(){
	
	long long a,b,res;
	int n;
	
	cin>>n;
	while(n--){
		cin>>a>>b;
		if(a==0 && b==0){
		cout<<0<<"\n";
		}else{
		res= pow(26,a)*pow(10,b);
		cout<<res<<"\n";	
		}
		
	}
	
	return 0;
}