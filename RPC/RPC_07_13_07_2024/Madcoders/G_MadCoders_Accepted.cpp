#include <bits/stdc++.h>
using namespace std;

vector<pair<string, string>> intercambiar_prefijos(const string &a, const string &b) {
    vector<pair<string, string>> resultados;
    for (int i = 1; i < a.size(); ++i) {
        for (int j = 1; j < b.size(); ++j) {
            string nuevo_a = b.substr(0, j) + a.substr(i);
            string nuevo_b = a.substr(0, i) + b.substr(j);
            if (nuevo_a[0] != '0' && nuevo_b[0] != '0') {
                resultados.push_back({nuevo_a, nuevo_b});
            }
        }
    }
    return resultados;
}

bool es_valido(const string &x, const string &y, const string &z, char operacion) {
    long long a = stoll(x);
    long long b = stoll(y);
    long long c = stoll(z);
    if (operacion == '+') {
        return a + b == c;
    } else if (operacion == '*') {
        return a * b == c;
    }
    return false;
}

string corregir_ecuacion(const string &expresion) {
    stringstream ss(expresion);
    string x, operacion, y, igual, z;
    ss >> x >> operacion >> y >> igual >> z;

    if (es_valido(x, y, z, operacion[0])) {
        return x + " " + operacion + " " + y + " " + igual + " " + z;
    }

    vector<pair<string, string>> intercambios;

    // Intercambiar x y y
    intercambios = intercambiar_prefijos(x, y);
    for (auto &nuevo : intercambios) {
        if (es_valido(nuevo.first, nuevo.second, z, operacion[0])) {
            return nuevo.first + " " + operacion + " " + nuevo.second + " " + igual + " " + z;
        }
    }


    intercambios = intercambiar_prefijos(y, z);
    for (auto &nuevo : intercambios) {
        if (es_valido(x, nuevo.first, nuevo.second, operacion[0])) {
            return x + " " + operacion + " " + nuevo.first + " " + igual + " " + nuevo.second;
        }
    }

    intercambios = intercambiar_prefijos(x, z);
    for (auto &nuevo : intercambios) {
        if (es_valido(nuevo.first, y, nuevo.second, operacion[0])) {
            return nuevo.first + " " + operacion + " " + y + " " + igual + " " + nuevo.second;
        }
    }

    return "No se encontró una ecuación válida";
}

int main() {
    string expresion;
    getline(cin, expresion);
    cout << corregir_ecuacion(expresion) << endl;
    return 0;
}
