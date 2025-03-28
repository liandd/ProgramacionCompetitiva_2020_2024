/******************************************************************************

                              Online C++ Debugger.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Debug" button to debug it.

*******************************************************************************/


#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int > pii;

#define ff first
#define ss second

/// Complexity: O(|V|^3)
/// Tested: https://t...content-available-to-author-only...l.com/ycpq8eyl problem G
typedef double type;
struct matching_weighted {
  int l, r;
  vector<vector<type>> c;
  matching_weighted(int l, int r) : l(l), r(r), c(l, vector<type>(r)) {
    assert(l <= r);
  }
  void add_edge(int a, int b, type cost) { c[a][b] = cost; }
  type matching() {
    vector<type> v(r), d(r); // v: potential
    vector<int> ml(l, -1), mr(r, -1); // matching pairs
    vector<int> idx(r), prev(r);
    iota(idx.begin(), idx.end(), 0);
    auto residue = [&](int i, int j) { return c[i][j]-v[j]; };
    for(int f = 0; f < l; ++f) {
      for(int j = 0; j < r; ++j) {
        d[j] = residue(f, j);
        prev[j] = f;
      }
      type w;
      int j, l;
      for (int s = 0, t = 0;;) {
        if(s == t) {
          l = s;
          w = d[ idx[t++] ];
          for(int k = t; k < r; ++k) {
            j = idx[k];
            type h = d[j];
            if (h <= w) {
              if (h < w) t = s, w = h;
              idx[k] = idx[t];
              idx[t++] = j;
            }
          }
          for (int k = s; k < t; ++k) {
            j = idx[k];
            if (mr[j] < 0) goto aug;
          }
        }
        int q = idx[s++], i = mr[q];
        for (int k = t; k < r; ++k) {
          j = idx[k];
          type h = residue(i, j) - residue(i, q) + w;
          if (h < d[j]) {
            d[j] = h;
            prev[j] = i;
            if(h == w) {
              if(mr[j] < 0) goto aug;
              idx[k] = idx[t];
              idx[t++] = j;
            }
          }
        }
      }
      aug: for (int k = 0; k < l; ++k)
        v[ idx[k] ] += d[ idx[k] ] - w;
      int i;
      do {
        mr[j] = i = prev[j];
        swap(j, ml[i]);
      } while (i != f);
    }
    type opt = 0;
    for (int i = 0; i < l; ++i)
      opt += c[i][ml[i]]; // (i, ml[i]) is a solution
    return opt;
  }
};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
  
    //freopen("input.txt", "r", stdin );
    int n;
    while( cin >> n )
    {
        if( n == 0 ) break;
        
        vector< pii > l( n ), r ( n );
        for( int i = 0; i < n; ++ i )
        {
            cin >> l[i].ff >> l[i].ss;
        }
        
         for( int i = 0; i < n; ++ i )
        {
            cin >> r[i].ff >> r[i].ss;
        }
        
        matching_weighted st( n, n );
        for( int i = 0; i < n; ++ i )
        {
            for( int j = 0; j < n; ++ j )
            {
                int dx = l[i].ff - r[j].ff;
                int dy = l[i].ss - r[j].ss;
                
                double cost = sqrt( dx * dx + dy * dy );
                st.add_edge( i, j, cost );
            }
        }
        cout << fixed << setprecision( 3 ) << st.matching() << '\n';
    }
   
    
    return 0;
}