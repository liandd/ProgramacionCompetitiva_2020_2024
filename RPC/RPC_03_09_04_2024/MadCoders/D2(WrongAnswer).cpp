#include<bits/stdc++.h>
using namespace std;
bool canWin(long long n) {
    if (n == 1) return false;
    long long sq = sqrt(n);
    if (sq * sq != n) return true;
    return n % 4 == 3;
}

int main() {
    long long n;
    cin >> n;
    if (canWin(n)) {
        cout << "Y" << endl;
    } else {
        cout << "N" << endl;
    }
    return 0;
}
