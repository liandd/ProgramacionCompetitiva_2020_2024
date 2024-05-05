#include <bits/stdc++.h>
using namespace std;

long long salida(long long p,long long q,long long n) {
	if(p == 0) return 0;
	if(p >= q)
        return n * (n + 1)/2 * (p/q) + salida(p % q, q, n);
	return n * (p*n/q) + n/q - salida(q, p, p*n/q);
}

int mcd(int a, int b) {
   if (b == 0) return a;
   return mcd(b, a % b);
}

int main(){
	int casos;
	cin>>casos;
	while(casos--){
		long long p,q,n;
		cin>>p>>q>> n;
		long long maxDivisor = mcd(p, q);
		cout<<n * (n+1)/2 * p-q * salida(p/maxDivisor, q/maxDivisor, n)<< '\n';
	}
}
