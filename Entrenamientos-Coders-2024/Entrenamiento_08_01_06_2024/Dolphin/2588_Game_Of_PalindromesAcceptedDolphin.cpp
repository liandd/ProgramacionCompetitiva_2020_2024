#include <bits/stdc++.h>
using namespace std;

int min_adiciones_para_palindromo(const string &secuencia) {
    unordered_map<char, int> frecuencia;
    for (char c : secuencia) {
        frecuencia[c]++;
    }
    
    int contador_impares = 0;
    for (const auto &par : frecuencia) {
        if (par.second % 2 != 0) {
            contador_impares++;
        }
    }
    
    return max(0, contador_impares - 1);
}

int main() {
    string secuencia;
    while (cin >> secuencia) {
        cout << min_adiciones_para_palindromo(secuencia) << endl;
    }
    return 0;
}