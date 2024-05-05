#include <bits/stdc++.h>
using namespace std;
#define BITS 31

int main() {
	unsigned int t, n, mask, bit;
	cin>>t;
	while(t--) {
		cin>> n;
		mask = 0;
		for (int i = 0; i < BITS + 1; i++) {
			mask |= (1 << (n & BITS));
			bit = n & 1;
			n >>= 1;
			n |= (bit << BITS);
		}
		if(mask == 4294967295){
		    puts("yes");
		} else {
		    puts("no");
		}
	}
}