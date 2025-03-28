// I'm a paragraph. Click here to add your own text and edit me. It’s easy. 
// Just click “Edit Text” or double click me to add your own content 
// and make changes to the font. Feel free to drag and drop me anywhere 
// you like on your page. I’m a great place for you to tell a story 
// and let your users know a little more about you.

#include <bits/stdc++.h>
using namespace std;

#define sz(x) int(size(x))
#define all(x) begin(x), end(x)
#define rep(i, a, b) for(int i = (a); i < (b); i++)
using ll = long long;
using vi = vector<int>;
using pii = pair<int, int>;

const int oo = 1e9;
const int G = 101;
const int L = 5;

vi reqs[G][L];
vi dp[G][L];
bool cutoff[G][L];

void solve() {   
    int n;
    cin >> n;

    vector<tuple<int, char, int>> inp(n);
    vi ps;
    ps.reserve(n);

    for (auto& [g, l, p] : inp) {
        cin >> g >> l >> p;
        if (l == 'F') l = 'E';
        l -= 'A';
        p = -p;
        ps.push_back(p);
    }

    sort(all(ps));
    ps.erase(unique(all(ps)), end(ps));

    for (auto& [g, l, p] : inp) {
        p = lower_bound(all(ps), p) - begin(ps);
        reqs[g][l].push_back(p);
    }

    rep (j, 0, L) {
        dp[0][j].resize(sz(ps));
        dp[0][j][0] = -oo;
    }
    dp[0][L-1][0] = 0;
    cutoff[0][L-1] = 1;
    
    rep (g, 0, G) {
        if (g > 0) {
            rep (l, 0, L) {
                cutoff[g][l] = (l < L-1 && dp[g-1][l+1] >= dp[g-1][l]);
                dp[g][l] = cutoff[g][l] ? dp[g-1][l+1] : dp[g-1][l];
            }
        }

        rep (l, 0, L) 
            for (int i : reqs[g][l])
                dp[g][l][i]++;
    }

    for (int g = 100, l = 0; l < L-1; g--) 
        if (cutoff[g][l]) {
            cout << g << " ";
            l++;
        }
    cout << "\n";
} 

int main() {
    // cin.tie(0)->sync_with_stdio(0);
    // cin.exceptions(cin.failbit);

    // int t; cin >> t; while (t--)
    solve();

    return 0;
}