#include <bits/stdc++.h>

using namespace std;

long long sumDig(long long a) {
	long long sumD=0;

	while(a>0) {
		sumD+=a%10;
		a/=10;
	}

	return sumD;
}

long long cualEs(long long a, long long b) {
	long long sumA=sumDig(a);
	long long sumB=sumDig(b);

	if(sumA>9) {
		while(sumA>9) {
			sumA=sumDig(sumA);
		}
	}

	if(sumB>9) {
		while(sumB>9) {
			sumB=sumDig(sumB);
		}
	}


	if(sumA==sumB) { //xd
		return 0;
	} else if(sumA>sumB) {
		return 1;
	} else if(sumB>sumA) {
		return 2;
	}

	return 0; //no creo que entre aqui xd
}


int main() {

	long long m,n;

	while(cin>>n>>m) {

		if(n==0 && m==0) {
			break;
		} else {
			long long res=cualEs(n,m);
			cout<<res<<"\n";
		}
	}


	return 0;
}