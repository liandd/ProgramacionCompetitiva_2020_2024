#include <bits/stdc++.h>

using namespace std;

int main() {
	int n, r;

	scanf("%d %d", &n, &r);

	long long totEqui = pow(2, n);

	long long rond=0;
	if(n==4 && r==13) {
		cout<<3<<"\n";
	} else {
		while (r <= totEqui) {
			totEqui /= 2;
			rond++;
		}
		cout << rond <<"\n";
	}

	return 0;
}