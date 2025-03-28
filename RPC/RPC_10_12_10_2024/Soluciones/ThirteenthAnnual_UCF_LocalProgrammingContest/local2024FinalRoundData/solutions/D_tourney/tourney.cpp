
#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    k = 1 + (1<<n) - k;

    int ans = 0;
    while (k) {
        k /= 2;
        ans++;
    }
    ans = min(ans, n);

    cout << ans << endl;

    return 0;
}
