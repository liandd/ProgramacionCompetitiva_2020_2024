#include<bits/stdc++.h>

using namespace std;

bool mostrarPatron(const vector<string>& matriz, const vector<string>& patron, int filas, int columnasMatriz, int columnasPatron) {

    for (int desplazamiento = 0; desplazamiento <= columnasMatriz + columnasPatron - 1; ++desplazamiento) {
        for (int fila = 0; fila < filas; ++fila) {
            for (int col = max(0, desplazamiento - columnasPatron + 1); col < min(columnasMatriz, desplazamiento + 1); ++col) {
  
                if (patron[fila][col - desplazamiento + columnasPatron - 1] == '*' && matriz[fila][col] == '-') {
                    return false; 
                }
            }
        }
    }
    return true; 
}

int main() {
    int filas, columnasMatriz, columnasPatron;
    cin >> filas >> columnasMatriz >> columnasPatron;

    vector<string> matriz(filas), patron(filas);
    for (int i = 0; i < filas; ++i) {
        cin >> matriz[i] >> patron[i];
    }

    cout << (mostrarPatron(matriz, patron, filas, columnasMatriz, columnasPatron) ? "Y" : "N") << endl;

    return 0;
}