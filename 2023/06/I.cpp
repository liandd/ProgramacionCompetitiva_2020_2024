#include<bits/stdc++.h>
using namespace std;

const int maxn = 500010;
using ll = long long;

ll dp[maxn];
vector<ll> p[maxn];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    for (int i = 1; i <= n; ++i) {
        for (int j = 0; j <= min(m, n - i + 1); ++j) {
            ll x;
            cin >> x;
            p[i].push_back(x);
        }
    }

    p[n + 1].push_back(0);
    dp[1] = p[1][0];

    for (int i = 2; i <= n + 1; ++i) {
        dp[i] = dp[i - 1] + p[i][0];

        for (int j = max(1, i - m); j < i; ++j) {
            dp[i] = min(dp[i], dp[j] + p[i][0] - p[j][i - j]);
        }
    }

    cout << dp[n + 1] << "\n";
    return 0;
}
