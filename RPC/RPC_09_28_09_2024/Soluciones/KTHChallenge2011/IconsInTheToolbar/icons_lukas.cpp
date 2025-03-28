/* Sample solution to "Icons in the Toolbar" from KTH Challenge 2011.
 *
 * Author: Lukas Polacek
 */
#include <vector>
#include <numeric>
#include <algorithm>
#include <cstdio>
using namespace std;

typedef long long ll;
int main()
{
    int n;
    scanf("%d", &n);
    vector<ll> s(2 * n);
    for (int i = 0; i< 2 * n; i++)
        scanf("%lld", &s[i]);

    vector<ll> t(n);
    partial_sum(s.begin(), s.begin() + n, t.begin());
    vector<ll> u(2 * n + 1); u[2 * n] = 0;
    for (int i = 2 * n - 2; i >= 0; i -= 2)
        u[i] = s[i] + u[i + 2];

    ll res = 1LL<<62;
    for (int i = 1; i <= n; i++)
        res = min(res, (t[i - 1] + u[2 * i]) * (s[0] + s[i]));

    printf("%lld\n", res);
}
