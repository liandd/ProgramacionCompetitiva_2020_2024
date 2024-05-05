#include <bits/stdc++.h>
using namespace std;
#define all(x) begin(x), end(x)
#define sz(x) (ll)(x).size()
using ll = long long;
using ld = long double;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n;
    cin >> n;
    vector<ll> pos(n);
    bitset<2000002> libre;
    libre.set();
    for (ll i = 0; i < n; i++) {
        cin >> pos[i];
        libre[pos[i]] = false;
    }
    ll q;
    cin >> q;
    for (ll i = 0; i < q; i++) {
        ll id;
        cin >> id;
        id--;
        libre[pos[id]] = true;
		pos[id] = libre._Find_next(pos[id]);
        libre[pos[id]] = false;
        cout << pos[id] << endl;
    }
    return 0;
}
