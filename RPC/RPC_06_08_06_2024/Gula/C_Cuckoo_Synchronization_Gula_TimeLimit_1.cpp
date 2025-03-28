#include <bits/stdc++.h>

using namespace std;
int main() {

	int q;
	scanf("%d",&q);

	while(q--) {
		long long n,t;
		scanf("%lld %lld",&n,&t);
		int cont=0;
		t=t-1;
		for(int i=1; i<=n; i++) {
			if((t)%i==0) {
				cont++;
			}
		}

		printf("%d\n", cont);
	}





	return 0;
}