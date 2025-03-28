#include<bits/stdc++.h>

using namespace std;

const int MOD = 1000000007;

long long factorial(int n) {
    if (n <= 1) return 1;
    return (n * factorial(n - 1)) % MOD;
}

int main() {
    int a, b, c;
    cin >> a >> b >> c;

    long long total = factorial(a + b + c);
    long long invalidA = (a + 1) * factorial(a) % MOD * factorial(b) % MOD * factorial(c) % MOD;
    long long invalidB = (b + 1) * factorial(a) % MOD * factorial(b) % MOD * factorial(c) % MOD;
    long long invalidC = (c + 1) * factorial(a) % MOD * factorial(b) % MOD * factorial(c) % MOD;

    long long valid = (total - invalidA - invalidB - invalidC + MOD) % MOD;

    cout << valid << endl;

    return 0;
}
