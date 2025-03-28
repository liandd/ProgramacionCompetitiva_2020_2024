#include<bits/stdc++.h>
using namespace std;
int main(){
	
	int n,k;
	cin>>n>>k;
	if(n==1){
	cout<<k<<"\n";
	return 0;
	}
	
	if(n==0){
	cout<<0<<"\n";
	return 0;
	}
	
	if(k==0){
	cout<<0<<"\n";
	return 0;
	}
	
	int breaks = n-1, solve=0, i=0;
	
	while(i<=(k-breaks)){
	solve++;
	i = i+n;
	}
	
	cout<<solve-1<<"\n";
	
	return 0;
}
