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

	int a=0,b=0;

	for(auto i: puntos) {
		for(auto j: puntos) {
			area=i*j;
			if(area==c) {
				a=i;
				b=j;
				break;
			}
		}
	}

	if(a>b) {
		cout<<b<<" "<<a;
	} else {
		cout<<a<<" "<<b;
	}

	return 0;
}