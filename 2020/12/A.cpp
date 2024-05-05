#include <bits/stdc++.h>
using namespace std;

int main(){
	int g, p, t;
	cin>>g>>p>>t;
	
	int individual = (g * p);
	int group = (p * t) + g;
	
	if(individual < group) cout<<1<<endl;
	else if(individual > group) cout<<2<<endl;
	else cout<<0<<endl;
	return 0;
}
