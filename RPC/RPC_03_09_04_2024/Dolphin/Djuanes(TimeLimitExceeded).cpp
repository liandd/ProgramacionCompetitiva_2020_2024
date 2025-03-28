#include<bits/stdc++.h>
using namespace std;
int num,rel,cont,res;
int main(){
	cin>>num;
	for (int i=1;i<=num;i++){
		rel=num%i;
		if(rel==0){
		cont++;	
		}
	}
	res=cont%2;
	if(res==0){
		cout<<"Y\n";
	}else{
		cout<<"N\n";
	}
	
	return 0;
}
