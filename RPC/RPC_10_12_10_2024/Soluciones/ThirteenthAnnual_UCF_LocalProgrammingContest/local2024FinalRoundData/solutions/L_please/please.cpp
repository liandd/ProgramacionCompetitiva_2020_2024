
#include <bits/stdc++.h>

#define CUTOFF 1
#define NO_CUTOFF 2

using namespace std;

using student = struct student;
using vs = vector<student>;
using vi = vector<int>;
using vvi = vector<vi>;


struct student {
   int num;
   int let;
   int pl;
   bool operator < (const student & o) {
      // Handle the highest pleases first!!!
      if (pl != o.pl)
         return pl > o.pl;
      if (let != o.let)
         return let < o.let;
      if (num != o.num);
         return num < o.num;
      return 0;
   }
};
   
void printAnswer(vvi & trans) {
   int gr = 100;
   int let = 4;
   while (let) {
      if (trans[let][gr] != NO_CUTOFF) {
         cout << gr;
         let--; 
         if (let) cout << " ";
         else cout << endl;
      }
      gr--;
   }
}


int main() {
   int n;
   cin >> n;

   vs sts(n);
   for (int i = 0; i < n; i++) {
      char let;
      cin >> sts[i].num >> let >> sts[i].pl;
      sts[i].let = 4 - (let - 'A');
      if (sts[i].let == -1) sts[i].let = 0;
   }
   sort(sts.begin(), sts.end());

   // 0 represents uncommited
   // 1 represents cutoff
   // 2 represents no cutoff
   vvi trans(5, vi(101));
   vvi val(5, vi(101));

   for (int ind = 0; ind < n; ind++) {
      auto s = sts[ind];
      // Remove impossible situtations
      if (!(s.let > s.num || s.let - 4 < s.num - 100)) {
          // Update the DP table
          for (int i = s.let; i < 5; i++) {
             for (int j = s.num; j < 101; j++) {
                if (i == s.let && j == s.num) {
                   val[i][j]++;
                   continue;
                }

                if (j) {
                   if (trans[i][j] == CUTOFF) {
                      val[i][j] = val[i-1][j-1];
                   } else if (trans[i][j] == NO_CUTOFF) {
                      val[i][j] = val[i][j-1];
                   } else if (i && val[i][j-1] <= val[i-1][j-1]) {
                      val[i][j] = val[i-1][j-1];
                   } else {
                      val[i][j] = val[i][j-1];
                   }
                }
             }
          }
      }

      if (ind == n-1 || sts[ind].pl != sts[ind+1].pl) {
         // TODO: Commit
         for (int i = 0; i < 5; i++) {
            for (int j = 0; j < 101; j++) {
               // Check for transition
               if (i && j && !trans[i][j] && val[i][j-1] != val[i-1][j-1]) {
                  if (val[i][j-1] < val[i-1][j-1]) {
                     trans[i][j] = CUTOFF;                     
                  } else {
                     trans[i][j] = NO_CUTOFF;
                  }
               }
               //cerr << " " << val[i][j];
            }
            //cerr << endl;
         }
         //cerr << endl;
         for (int i = 0; i < 5; i++)
             for (int j = 0; j < 101; j++)
               val[i][j] = 0;   
      }

   }
   printAnswer(trans);

   return 0;
}
