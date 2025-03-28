
#include <bits/stdc++.h>

#define sz(a) ((int)(a).size())
#define rep(a,b,c) for(int a = (b); a < (c); a++)

using namespace std;
using vi = vector<int>;
using vvi = vector<vi>;

// Thank you kactl
pair<int, vi> hungarian(const vector<vi> &a) {
	if (a.empty()) return {0, {}};
	int n = sz(a) + 1, m = sz(a[0]) + 1;
	vi u(n), v(m), p(m), ans(n - 1);
	rep(i,1,n) {
		p[0] = i;
		int j0 = 0; // add "dummy" worker 0
		vi dist(m, INT_MAX), pre(m, -1);
		vector<bool> done(m + 1);
		do { // dijkstra
			done[j0] = true;
			int i0 = p[j0], j1, delta = INT_MAX;
			rep(j,1,m) if (!done[j]) {
				auto cur = a[i0 - 1][j - 1] - u[i0] - v[j];
				if (cur < dist[j]) dist[j] = cur, pre[j] = j0;
				if (dist[j] < delta) delta = dist[j], j1 = j;
			}
			rep(j,0,m) {
				if (done[j]) u[p[j]] += delta, v[j] -= delta;
				else dist[j] -= delta;
			}
			j0 = j1;
		} while (p[j0]);
		while (j0) { // update alternating path
			int j1 = pre[j0];
			p[j0] = p[j1], j0 = j1;
		}
	}
	rep(j,1,m) if (p[j]) ans[p[j] - 1] = j - 1;
	return {-v[0], ans}; // min cost
}

int canDo(vvi & orig, int lim, int ps) {
    int n = sz(orig), m = sz(orig[0]);
    vvi newTab(n, vi(m + (n-ps), 0));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) { 
            newTab[i][j] = orig[i][j];
        }
    }
    return (hungarian(newTab).first <= lim);
}

int main() {
    int stud, prob, time_lim, pairs;
    cin >> stud >> prob >> time_lim;
    vvi orig(stud, vi(prob, time_lim + 1));
    //for (int i = 0; i < pairs; i++) {
    for (int i = 0; i < stud; i++) {
        for (int j = 0; j < prob; j++) {
            int sid, pid, tim;
            cin >> tim;
            sid--; pid--;
            sid = i;
            pid = j;
            if (!tim) tim = time_lim + 1;
            orig[sid][pid] = min(orig[sid][pid], tim);
        }
    }

    int lo = 1, hi = min(stud, prob);
    int ans = 0;
    while (lo <= hi) {
        int mid = (lo + hi) / 2;
        if (canDo(orig, time_lim, mid)) {
            ans = mid; lo = mid + 1;
        } else {
            hi = mid - 1;
        }
    }
    cout << ans << endl;
    return 0;
}
