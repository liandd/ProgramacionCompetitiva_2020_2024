#include<bits/stdc++.h>

using namespace std;

int main() {
    int dr, alyssa, konari;
    cin >> dr >> alyssa >> konari;

    for (int a = 1; a <= 150; ++a) {
        for (int k = 1; k <= 150; ++k) {
            if ((a * alyssa) + (k * konari) == dr) {
                cout << "1" << endl;
                return 0;
            }
        }
    }

    cout << "0" << endl;
    return 0;
}
