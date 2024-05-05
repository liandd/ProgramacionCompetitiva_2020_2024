#include <bitset>
#include <iostream>

using namespace std;

bitset<500> dp[500];

int main() {
  int n, m;
  cin >> n >> m;
  for(int i = 0; i < n; i++) {
    dp[i].set(i);
    int k;
    cin >> k;
    while(k--) {
      int x;
      cin >> x;
      dp[--x].set(i);
    }
  }
  for(int i = 0; i < n; i++) for(int j = 0; j < n; j++) if(dp[i][j]) dp[i] |= dp[j];
  for(int i = 0; i < n; i++) for(int j = 0; j < n; j++) if(dp[i][j]) dp[i] |= dp[j];
  for(int i = 0; i < n; i++) cout << "01"[dp[i].count() > m] << "\n";
}
