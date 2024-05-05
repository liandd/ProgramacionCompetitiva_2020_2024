#include<bits/stdc++.h>
using namespace std;

int main() {

  int d1, m1, y1, n1;
  cin >> d1 >> m1 >> y1 >> n1;

  int d2, m2, y2;
  cin >> d2 >> m2 >> y2;

  int dp=(y2-y1)*360 + (m2-m1)*30 + (d2-d1);
  int dw=(n1-1+dp)%7+1;

  cout << dw <<"\n";

  return 0;
}
