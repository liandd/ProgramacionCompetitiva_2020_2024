#include <bits/stdc++.h>

using namespace std;

int main() {
	int t;
	scanf("%d", &t);
    while(t--) {
		long long n;
		cin >> n;
		n--;
		if (n == 0) {
			printf("0 0\n");
			continue;
		}
		long long root = (long long) sqrt(n);
		long long x = 0;
		if (root % 2 != 0) {
			x = -root + (n - root * root);
		} else {
			x = root - (n - root * root);
		}
		long long lim = (root + 1) * (root + 1) - root * root;
		long long y = -root / 2;
		if (root % 2 != 0) {
			if (n - root * root <= lim / 2) {
				y += n - root*root;
			} else {
				y += lim / 2;
				y -= n - root * root - lim / 2;
			}
		}
		printf("%lld %lld\n", x, y);
	}
}