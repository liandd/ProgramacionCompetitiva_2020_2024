#include <bits/stdc++.h>

using namespace std;

int main(){
	
	long long n=0, a=0, b=0,  res=0;
	
	// n=amperios arbol
	// a=vatios watts
	// b=voltio volts
	
	scanf("%lld %lld %lld", &n  , &a  ,&b);
	
	res=a/b;
	
	if(res>=n){
		printf("%d\n", 1);
	}else{
		printf("%d\n", 0);
	}
	
	return 0;
}