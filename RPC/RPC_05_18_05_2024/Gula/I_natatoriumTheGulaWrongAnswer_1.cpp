#include <bits/stdc++.h>

using namespace std;

bool primo( int x) {

	bool bandera=true;

	if(x==2) {
		bandera=true;
	} else if(x<=1) {
		bandera=false;
	} else {
		for(int j=2; j<=sqrt(x); j++) {
			if(x%j==0) {
				bandera=false;
			}
		}

	}

	return bandera;
}


int main() {
	int m;
	int x;
	long long c;
	scanf("%lld %d",&c,&m);
	
	vector<int> puntos;

	for(int i=0; i<m; i++) {
		scanf("%d",&x);
		if(primo(x)) {
			puntos.push_back(x);
		}

	}

	sort(puntos.begin(), puntos.end());
	
	long long area;
	
	int a,b;
	vector<int> re;
	for(auto i: puntos) {
		for(auto j: puntos) {
			if(i!=j) {
				area=i*j;
				if(area==c) {
				a=i; b=j;
				break;	
				}	
			}

		}
	}
	
	if(a>b){
		cout<<b<<" "<<a<<"\n";
	}else{
		cout<<a<<" "<<b<<"\n";
	}
	
	return 0;
}