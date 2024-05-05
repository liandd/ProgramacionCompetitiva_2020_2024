#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, i, k;
	cin >> n >> i >> k;

	double ciclos = 0;
	for (int j = 1; j <= n; j++) {
		double p = pow(double(j)/n,k) - pow(double(j-1)/n,k);
		ciclos += p * (j >= i ? (j+1)/2.0 : i);
	}
	cout << fixed << setprecision(9) << ciclos << endl;
}
