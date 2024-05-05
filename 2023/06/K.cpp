#include <bits/stdc++.h>
#define maxn 1010
using namespace std;

char s[maxn];
int a[maxn];

int main() {
    int i, j, n, k, pre = 0;
    
    cin >> n >> k;
    cin >> s;
    
    for (i = 0; i < n; ++i) {
        if (s[i] == 'L'){
        	a[i + 1] = 1;	
		}else{
			a[i + 1] = 0;
		}       
    }
    
    while (pre < n) {
        int t;
        t = a[pre] ^ 1;
        for (i = pre + 1;; ++i) {
            if (!k) {
                pre = n;
                break;
            }
            if (i > n) {
                pre = n;
                break;
            }
            if (a[i] ^ t) {
                pre = i;
                k--;
                break;
            }

            t ^= 1;
        }
    }    
    cout << k <<"\n";
	return 0;
}
