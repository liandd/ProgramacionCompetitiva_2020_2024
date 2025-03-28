
#include <bits/stdc++.h>

using namespace std;

using ll2 = long long int;
using ll = __int128;

int main() {
   ll2 p1, q1, p2, q2;
   cin >> p1 >> q1 >> p2 >> q2;
   if (!p1 || !q1 || !p2 || !q2) {
      cout << "0\n";
      return 0;
   }
   q1+=p1;
   q2+=p2;

   if (p1 * q2 > p2 * q1) {
      swap(p1,p2);
      swap(q1, q2);
   }

   int ans = 0;
   ll q3 = 1;
   while (1) {
      q3 *= 2;
      ans++;
      ll p3 = (q3*p2)/q2;
      if (q3 * p1 <= p3 * q1) break;
   }

   cout << ans << endl;
   return 0;
}
