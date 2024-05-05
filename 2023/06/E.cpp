#include<bits/stdc++.h>
using namespace std;

int main() {
    long long n;
    cin >> n;

    double ans = (n == 1) ? 1.0 : ((n == 2) ? 0.0 : 1.0/3.0 + 2.0/3.0 * pow(-0.5, n-1));
    ans *= 100;

    cout << fixed << setprecision(6) << ans << " " << 100 - ans << endl;
    return 0;
}
