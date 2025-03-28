
#include <bits/stdc++.h>

typedef long long int lli;
typedef struct edge edge;

struct edge {
    int s, e;
    lli l;
};

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    lli oo = 1000000;
    oo *= oo;
    vector<lli> dist(n, oo);
    dist[0] = 0;
    vector<edge> es(m);
    for (int i = 0; i < m; i++) {
        char c;
        cin >> es[i].s >> es[i].e >> c >> es[i].l;
        es[i].s--; es[i].e--;
        if (c == 'r') es[i].l *= -1;
    }
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            lli ndist = dist[es[j].s] + es[j].l;
            if (ndist < dist[es[j].e])
                dist[es[j].e] = ndist;
        }
    }

    for (int i = 0; i < n; i++) {
        if (dist[i] < 0) {
            cout << i + 1 << endl;
        }
    }

    return 0;
}
