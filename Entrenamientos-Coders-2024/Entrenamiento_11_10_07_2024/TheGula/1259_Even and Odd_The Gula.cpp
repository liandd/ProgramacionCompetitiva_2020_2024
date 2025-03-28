#include <bits/stdc++.h>

using namespace std;
int main(){
	
	vector<int> par;
	vector<int> impar;
	
	int x;
	int z;	
	
	scanf("%d",&x);
	while(x--){
		scanf("%d",&z);
		if(z&1){
		    impar.push_back(z);
		}else{
			par.push_back(z);
		}
		
	}
	
	sort(par.begin(), par.end());
	sort(impar.begin(), impar.end(),greater<int>());
	
	for(auto i:par){
		cout<<i<<"\n";
	}
	
	for(auto i:impar){
		cout<<i<<"\n";
	}
	
	
	return 0;
}