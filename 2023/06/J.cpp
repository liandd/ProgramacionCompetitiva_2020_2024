#include<bits/stdc++.h>
#define maxn 100010
using namespace std;

char s[maxn];
int b[maxn];
int p[5], dp[maxn][5];

int work(int n) {
    int i, j, ans = maxn;
    for(i = 1; i <= 4; ++i)
        dp[0][i] = maxn;
    dp[0][0] = 0;
    for(i = 1; i <= n; ++i) {
        for(j = 0; j <= 4; ++j)
            dp[i][j] = dp[i - 1][j] + 1;
        for(j = 0; j <= p[b[i]]; ++j)
            dp[i][p[b[i]]] = min(dp[i][p[b[i]]], dp[i - 1][j]);
    }
    for(i = 0; i <= 4; ++i)
        ans = min(ans, dp[n][i]);
    return ans;
}

int main() {
    int i, j, n, m, ans = maxn;

    cin >> s;
    n = strlen(s);
    for(i = 0; i < n; ++i) {
        if(s[i] == 's')
            b[i + 1] = 1;
        if(s[i] == 'h')
            b[i + 1] = 2;
        if(s[i] == 'c')
            b[i + 1] = 3;
        if(s[i] == 'd')
            b[i + 1] = 4;
    }
    for(i = 1; i <= 4; ++i)
        p[i] = i;
    for(i = 1; i <= 24; ++i) {
        ans = min(ans, work(n));
        if(i < 24)
            next_permutation(p + 1, p + 5);
    }
    cout << ans <<"\n";
    return 0;
}
