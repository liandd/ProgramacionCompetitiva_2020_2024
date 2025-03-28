#include<bits/stdc++.h>

using namespace std;

pair<int, int> encontrar_lados_piscina(long long superficie, int num_primos, vector<int>& primos) {
    unordered_set<int> primos_set(primos.begin(), primos.end());

    for (int p1 : primos) {
        if (superficie % p1 == 0) {
            long long p2 = superficie / p1;
            if (primos_set.find(p2) != primos_set.end() && p1 != p2) {
                return {min(p1, (int)p2), max(p1, (int)p2)};
            }
        }
    }
    return {0, 0};
}

int main() {

    long long superficie;
    int num_primos;


    cin >> superficie >> num_primos;
    vector<int> primos(num_primos);
    for (int i = 0; i < num_primos; ++i) {
        cin >> primos[i];
    }

    pair<int, int> resultado = encontrar_lados_piscina(superficie, num_primos, primos);

    if (resultado.first != 0) {
        cout << resultado.first << " " << resultado.second << endl;
    } else {
        cout << "No se encontró solución" << endl;
    }

    return 0;
}
