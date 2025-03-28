#include <bits/stdc++.h>
using namespace std;

vector<string> encontrarRangosLetras(string entrada) {
    vector<string> rangos;
    set<char> letras;
    entrada.erase(remove(entrada.begin(), entrada.end(), ' '), entrada.end());
    entrada.erase(unique(entrada.begin(), entrada.end()), entrada.end());

    sort(entrada.begin(), entrada.end());

    for (int i = 0; i < entrada.size(); ++i) {
        letras.insert(entrada[i]);
        if (i + 1 == entrada.size() || entrada[i + 1] - entrada[i] > 1) {
            if (letras.size() > 1) {
                string rango = *letras.begin() + string(":") + *letras.rbegin();
                rangos.push_back(rango);
            } else {
                string unica = *letras.begin() + string(":") + *letras.begin();
                rangos.push_back(unica);
            }
            letras.clear();
        }
    }

    return rangos;
}

int main() {
    string linea;
    while (getline(cin, linea)) {
        vector<string> rangos = encontrarRangosLetras(linea);
        for (int i = 0; i < rangos.size(); ++i) {
            cout << rangos[i];
            if (i != rangos.size() - 1) {
                cout << ", ";
            }
        }
        cout << endl;
    }

    return 0;
}
