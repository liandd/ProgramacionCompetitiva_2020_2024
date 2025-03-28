#include<bits/stdc++.h>

using namespace std;

int main() {
    string entrada;
    cin >> entrada;

    long long contador = 0;
    int cuentaCeros = 0, cuentaUnos = 0, cuentaDos = 0;

    for (char c : entrada) {
        if (c == '0') ++cuentaCeros;
        else if (c == '1') ++cuentaUnos;
        else ++cuentaDos;
    }

    int totalCeros = cuentaCeros;

    for (char c : entrada) {
        if (c == '0') {
            --cuentaCeros;
        } else if (c == '1') {

            contador += cuentaCeros;
        } else { // c == '2'

            contador += cuentaCeros + cuentaUnos;
        }
    }

    cout << contador << endl;

    return 0;
}
