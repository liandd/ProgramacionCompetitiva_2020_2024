#include<bits/stdc++.h>
using namespace std;
using ll = long long;

const int MAXN = 105;
const int MAXQ = 1e5+5;
const int INF = 1e9;

int n, q;
int a[MAXN];
int memo[MAXQ];

int solve(int k) {
    if (k <= n) return a[k];
    if (memo[k] != -1) return memo[k];
    int ans = INF;
    for (int i = 1; i <= k/2; i++) {
        ans = min(ans, solve(i) + solve(k-i));
    }
    return memo[k] = ans;
}

int main() {
    memset(memo, -1, sizeof memo);
    cin >> n >> q;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    while (q--) {
        int k;
        cin >> k;
        cout << solve(k) << "\n";
    }
    return 0;
}

