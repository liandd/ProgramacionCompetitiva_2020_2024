#include <bits/stdc++.h>

using namespace std;

int main (){

	int a, b;
	
	cin>>a;
	cin>>b;
	
	int re=0;
	int c=a*12+b;
	
	int aT,mT;
	
	if(c<=12){
		re=c*15;
	}
	
	else if(c>12 && c<=24){
		c=c-12;
		re=15*12+9*c;
	}
	
	else{
		c=c-24;
		re=15*12+9*12+c*4;
	}
	
	aT=re/12;
	mT=re%12;
	
	cout<<aT<<" "<<mT<<endl;
	return 0;
}
