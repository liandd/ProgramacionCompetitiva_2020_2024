
#include <bits/stdc++.h>

using namespace std;

int main() {
   string s;
   vector<int> seen(10);
   cin >> s;
   for (auto x : s) {
      if ('0' <= x && x <= '9') seen[x-'0'] = 1;
   }
   int ans = 0;
   for (auto x : seen) ans += x;
   cout << ans << endl;
   return 0;
}
