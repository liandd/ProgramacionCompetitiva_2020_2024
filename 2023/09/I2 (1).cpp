#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, q;
    cin >> n >> q;

    map<string, int> interseccionAIndice;
    vector<string> calles(n);
    for (int i = 0; i < n; ++i) {
        cin >> calles[i];
        interseccionAIndice[calles[i]] = i;
    }

    for (int i = 0; i < q; ++i) {
        string inicio, fin;
        cin >> inicio >> fin;

        int indiceInicio = interseccionAIndice[inicio];
        int indiceFin = interseccionAIndice[fin];

        if (indiceInicio > indiceFin) {
            swap(indiceInicio, indiceFin);
        }

        int diferencia = indiceFin - indiceInicio;
        if (diferencia == 1) {
            cout << "0\n";
        } else {
            cout << (diferencia - 1) << "\n";
        }
    }

    return 0;
}
