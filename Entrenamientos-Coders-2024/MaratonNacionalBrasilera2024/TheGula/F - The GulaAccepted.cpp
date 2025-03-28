#include <bits/stdc++.h>
using namespace std;

int main(){
	long long n, a=0, b=1 ,c;
	scanf("%d", &n);
	for(int i=0; i<n; i++){
		c=a+b;
		a=b;
		b=c;

	}
    cout<<c<<"\n";

	return 0;
}
