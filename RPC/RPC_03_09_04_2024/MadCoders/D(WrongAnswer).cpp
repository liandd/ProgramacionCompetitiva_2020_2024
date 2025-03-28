#include<bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long n;
    cin >> n;

    int cuenta = 0;

    //  factores primos de 2.
    if (n % 2 == 0) {
        cuenta++;
        while (n % 2 == 0) {
            n /= 2;
        }
    }

    // factores primos impares.
    for (long long i = 3; i * i <= n; i += 2) {
        if (n % i == 0) {
            cuenta++;
            while (n % i == 0) {
                n /= i;
            }
        }
    }

    if (n > 1) {
        cuenta++;
    }

    if (cuenta > 1) {
        cout << "Y\n";
    } else {
        cout << "N\n";
    }

    return 0;
}
