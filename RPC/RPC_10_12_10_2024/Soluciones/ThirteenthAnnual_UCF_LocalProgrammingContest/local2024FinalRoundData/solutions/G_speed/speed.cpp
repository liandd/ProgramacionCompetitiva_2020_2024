
#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ld = long double;
using vi = vector<int>;
using vvi = vector<vi>;
using vd = vector<ld>;

int main() {
   int n;
   ll L;
   cin >> n >> L;
   vvi boosts(n, vi(3));
   for (int i = 0; i < n; i++) {
      for (int j = 0; j < 3; j++) {
         cin >> boosts[i][j];
      }
   }
   sort(boosts.begin(), boosts.end());

   vd times(n);
   for (int i = 0; i < n; i++) times[i] = boosts[i][0];
   ld ans = L;
   for (int i = 0; i < n; i++) {
      int end = boosts[i][0] + boosts[i][1] * boosts[i][2];
      for (int j = i + 1; j < n; j++) {
         if (end <= boosts[j][0]) {
            times[j] = min(times[j], times[i] + boosts[j][0] - end + boosts[i][2]);
         }
      }
      if (end <= L) {
         ans = min(ans, times[i] + L - end + boosts[i][2]);
      } else {
         ans = min(ans, times[i] + (L-boosts[i][0]) / ((ld)(boosts[i][1])));
      }
   }

   cout << setprecision(12) << fixed << ans << endl;

   return 0;
}
