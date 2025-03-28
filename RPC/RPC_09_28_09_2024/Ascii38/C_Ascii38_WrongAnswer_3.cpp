#include <bits/stdc++.h>

using namespace std;

int main() {
  long long r, l;
  cin >> r >> l;

  if (l >= r) {
    cout << fixed << setprecision(10) << 0.0 << endl;
  } else {

    double probability =
        1.0 - (static_cast<double>(l) * l) / (static_cast<double>(r) * r);
    cout << fixed << setprecision(10) << probability << endl;
  }

  return 0;
}
