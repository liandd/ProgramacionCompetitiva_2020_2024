
#include <bits/stdc++.h>

// The area is probably a circle...
// So find the diameter using binary searches

using namespace std;

using ld = long double;

int main() {
   ld w,x1,y1;
   ld s,x2,y2;
   cin >> w >> x1 >> y1;
   cin >> s >> x2 >> y2;
   
   ld dx = x1-x2, dy = y1-y2;
   ld D = sqrt(dx*dx+dy*dy);
   
   ld lo = 0;
   ld hi = D;

   for (int i = 0; i < 100; i++) {
      ld mid = (lo + hi) / 2;
      ld oD = D - mid;

      ld fs = s / (mid * mid);
      ld fw = w / (oD * oD);

      if (fs > fw) {
         lo = mid;
      } else {
         hi = mid;
      }
   }

   ld st = lo;

   lo = D;
   hi = D + 1;

   // Loop until hi is hi enough
   while (1) {
      ld fs = s / (hi * hi);
      ld fw = w / ((hi-D) * (hi-D));
      if (fs > fw) break;
      hi *= 2;
   }

   
   for (int i = 0; i < 100; i++) {
      ld mid = (lo + hi) / 2;
      ld oD = mid - D;

      ld fs = s / (mid * mid);
      ld fw = w / (oD * oD);

      if (fs < fw) {
         lo = mid;
      } else {
         hi = mid;
      }
   }

   ld en = lo;

   ld r = (en-st)/2;

   cout << setprecision(12) << fixed << (r*r*M_PI) << endl;

   return 0;
}
