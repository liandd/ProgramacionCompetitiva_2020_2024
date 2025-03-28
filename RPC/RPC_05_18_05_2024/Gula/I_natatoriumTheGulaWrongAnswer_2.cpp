#include <bits/stdc++.h>

using namespace std;

int main() {
	int m;
	int x;
	long long c;
	scanf("%lld %d",&c,&m);

	set<int> puntos;

	for(int i=0; i<m; i++) {
		scanf("%d",&x);
		puntos.insert(x);

	}
	
	long long area;
	
	int a,b;

	for(auto i: puntos) {
		for(auto j: puntos) {
			if(i!=j) {
				area=i*j;
				if(area==c) {
					a=i;
					b=j;
					break;
				}
			}

		}
	}

	if(a>b) {
		cout<<b<<" "<<a<<"\n";
	} else {
		cout<<a<<" "<<b<<"\n";
	}

	return 0;
}