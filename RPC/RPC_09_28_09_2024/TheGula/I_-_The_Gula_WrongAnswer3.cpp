#include <bits/stdc++.h>

using namespace std;

int main() {

	int m=0;

	scanf("%d", &m);

	vector <long long> arriba(m);
	vector <long long> abajo(m);

	for(int i=0; i<m; i++) {
		scanf("%lld", &arriba[i]);
	}
	
	sort(arriba.rbegin(), arriba.rend());

	for(int i=0; i<m; i++) {
		scanf("%lld", &abajo[i]);
	}
	
	sort(abajo.rbegin(), abajo.rend());
	
	
	long long nose=abajo[0]+arriba[0];
	
	long long sum=0;
	for(int i=0; i<m; i++) {	
		sum+=min(arriba[i], abajo[i]);
	}
	
	long long res= nose*sum;
	
	printf("%lld\n", res);

	return 0;
}