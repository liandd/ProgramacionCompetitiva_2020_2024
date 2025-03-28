
#include <bits/stdc++.h>

using namespace std;

int main() {
   int m, ans = 0;
   string str;
   cin >> str;
   int n = str.size();
   cin >> m;

   vector<int> bptrs(26), skips(26);
   for (int i = 0; i < n; i++) {
      int index = str[i] - 'a';
      for (int j = 0; j < 26; j++) {
         if (j == index) continue;
         skips[j]++;
         while (skips[j] > m) {
            skips[j] -= ('a' + j != str[bptrs[j]++]);
         }
      }
      ans = max(ans, i + 1 - skips[index] - bptrs[index]);
   }

   cout << ans << endl;

   return 0;
}
