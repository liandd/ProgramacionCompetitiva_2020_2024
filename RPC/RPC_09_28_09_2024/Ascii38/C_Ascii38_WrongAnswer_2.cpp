#include <bits/stdc++.h>
using namespace std;

#define pl(x) printf("%.10lf\n", x)
#define PI 3.1415926535897932384626

int main() {
  double r, l, p;
  cin >> r >> l;

  double p_l = 2 * l;
  double p_r = 2 * PI * r;

  if (p_l >= p_r) {
    p = 0.0;
  } else if (p_l >= p_r / 2) {
    p = 0.0;
  } else {
    p = 1 - (p_l / p_r);
  }

  pl(p);
  return 0;
}
