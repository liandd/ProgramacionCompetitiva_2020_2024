#include <bits/stdc++.h>

using namespace std;

int main() {

	int n=2, m=0;

	scanf("%d", &m);

	vector <int> arriba(m);
	vector <int> abajo(m);

	for(int i=0; i<m; i++) {
		scanf("%d", &arriba[i]);
	}
	
	sort(arriba.rbegin(), arriba.rend());

	for(int i=0; i<m; i++) {
		scanf("%d", &abajo[i]);
	}
	
	sort(abajo.rbegin(), abajo.rend());
	
	
	int nose=abajo[0]+arriba[0];
	
	int sum=0;
	for(int i=0; i<m; i++) {
		int nummax=max(arriba[i], abajo[i]);
		sum+=nummax;
	}
	
	long long res=nose*sum;
	
	printf("%lld\n", res);

	return 0;
}