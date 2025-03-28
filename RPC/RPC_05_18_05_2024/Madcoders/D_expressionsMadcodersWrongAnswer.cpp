#include <bits/stdc++.h>
using namespace std;

int main() {
    long long c;
    int m;
    int lado1, lado2;

    cin >> c >> m;
    vector<int> primos(m);
    
    for (int i = 0; i < m; ++i) {
        cin >> primos[i];
    }

    unordered_set<int> conjuntoPrimos(primos.begin(), primos.end());

    for (int i; i<primos.size(); i++) {
        if (c % primos[i] == 0) {
            long long otroPrimo = c / primos[i];
            if (conjuntoPrimos.count(otroPrimo) && otroPrimo != primos[i]) {
                lado1 = primos[i];
                lado2 = otroPrimo;
                break;
            }
        }
    }

    if (lado1 > lado2) {
        int aux = lado1;
        lado1 = lado2;
        lado2 = aux;
    }

    cout << lado1 << " " << lado2 << endl;

    return 0;
}
