#include<bits/stdc++.h>
using namespace std;

int main(){
	int a, b, c;

	cin>>a>>b>>c;
	if((a+b)==c)cout<<1<<"\n";
	else if((a+c)==b)cout<<1<<"\n";
	else if((b+c)==a)cout<<1<<"\n";
	
	else if((a*b)==c)cout<<2<<"\n";
	else if((a*c)==b)cout<<2<<"\n";
	else if((b*c)==a)cout<<2<<"\n";

	else cout<<3<<"\n";

	return 0;
	
}
