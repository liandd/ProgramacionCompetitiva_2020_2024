#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main() {
    int ans = 1;
    ll a, b;
    cin >> a >> b;
    a--, b--;

    if (a > b)
        swap(a, b);

    for (int x = 1; x < a; ++x) {
        ll t = (a + x) * (a - x);
        ll y = (ll)floor(sqrt(t));
        if (y * y == t || (y + 1) * (y + 1) == t) {
            if (!(x * b % a) && !(y * b % a)) {
                ans++;
            }
        }
    }

    if (a != b)
        ans *= 2;

    cout << ans << endl;
    return 0;
}

