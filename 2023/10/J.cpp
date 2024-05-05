#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long n, k;
    cin >> n >> k;

    long long cajas = (n + k - 1) / k;
    long long menosLlena = n / cajas;

    cout << menosLlena << "\n";

    return 0;
}
