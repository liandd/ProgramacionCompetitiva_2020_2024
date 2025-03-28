
#include <bits/stdc++.h>

using namespace std;

int main() {
   int n, t;
   cin >> n >> t;
   vector<int> arr(n+1,0);
   while (t--) {
      char ty;
      cin >> ty;
      if (ty == 'R') {
         int loc;
         cin >> loc;
         while (loc <= n) {
            arr[loc]++;
            loc += (loc&-loc);
         }
      } else {
         int s, e;
         cin >> s >> e;
         s--;
         int ans = e - s;
         while (s) {
            ans += arr[s];
            s -= (s&-s);
         }
         while (e) {
            ans -= arr[e];
            e -= (e&-e);
         }
         cout << ans << endl;
      }
   }
   return 0;
}
