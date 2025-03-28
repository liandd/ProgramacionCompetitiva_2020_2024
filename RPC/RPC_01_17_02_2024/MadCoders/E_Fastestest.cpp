#include <bits/stdc++.h>
using namespace std;

int main() {
    int x, y;
    cin >> x >> y;

    if (x <= 0 || x >= 100 || y <= 0 || y >= 100) {
        return 0;
    }

    double factor = (static_cast<double>(x) / (100 - x)) / (static_cast<double>(y) / (100 - y));

    cout << fixed;


    if (factor - static_cast<int>(factor) == 0) {
        cout << setprecision(1) << factor << endl;
    } else {
        cout << setprecision(9) << factor << endl;
    }

    return 0;
}
