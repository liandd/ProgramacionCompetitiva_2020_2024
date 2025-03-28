#include<bits/stdc++.h>
using namespace std;

int longitud_sublista_creciente(const vector<int>& lista) {

    int max_longitud = 1;
    int longitud_actual = 1;

    for (int i = 1; i < lista.size(); ++i) {
        if (lista[i] > lista[i - 1]) {
            longitud_actual++;
        } else {
            max_longitud = max(max_longitud, longitud_actual);
            longitud_actual = 1;
        }
    }

    max_longitud = max(max_longitud, longitud_actual);

    return max_longitud;
}

int main() {
    int n;
    cin >> n;

    vector<int> lista(n);
    for (int i = 0; i < n; ++i) {
        cin >> lista[i];
    }

    int resultado = longitud_sublista_creciente(lista);
    cout << resultado << endl;

    return 0;
}
