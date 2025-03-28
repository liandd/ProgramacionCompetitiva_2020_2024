#include <bits/stdc++.h>
using namespace std;
#define lli long long int
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  lli n;
  while (cin >> n && n) {
    for (lli i = 1; i * i <= n; ++i) {
      if (i > 1) cout << " ";
      cout << i * i;
    }
    cout << "\n";
  }
  return 0;
}

