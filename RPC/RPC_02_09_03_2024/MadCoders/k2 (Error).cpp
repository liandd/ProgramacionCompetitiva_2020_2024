#include<bits/stdc++.h>

using namespace std;

int main()
{
    string entrada;
    cin >> entrada;

    int contador = 0;
    vector<int> arreglo(3, 0);

    for (char c : entrada) {
        arreglo[c - '0']++;
    }

    int zoo = arreglo[0], lago = arreglo[1], ciencia = arreglo[2];

    if (zoo <= lago) {
        contador = zoo + ciencia;
        zoo = 0;
    } else {
        contador = zoo + ciencia;
        lago = 0;
    }

    if (zoo > 0 && lago > 0) {
        int intercambios = min(zoo, lago);
        zoo -= intercambios;
        lago -= intercambios;
        contador += intercambios;
    }

    contador += zoo + lago;

    cout << contador;

    return 0;
}
