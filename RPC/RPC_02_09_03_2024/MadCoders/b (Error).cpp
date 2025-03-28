#include<bits/stdc++.h>
using namespace std;

int main() {
    long long n;
    cin >> n;

    int minimoAtaques = 0;
    while (n > 1) {

        if (n % 2 == 0) {
            n /= 2;
        }

        else {
            n -= 1;
        }
        minimoAtaques++;
    }

    if (n == 1) {
        minimoAtaques++;
    }

    cout << minimoAtaques;

    return 0;
}
