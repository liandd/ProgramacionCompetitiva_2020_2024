#include <bits/stdc++.h>
using namespace std;

int contar_intercambios(vector<int>& arr) {
    int n = arr.size();
    vector<pair<int, int>> arrpos(n);
    for (int i = 0; i < n; ++i) {
        arrpos[i] = {arr[i], i};
    }
    sort(arrpos.begin(), arrpos.end());
    vector<bool> visitado(n, false);
    int intercambios = 0;
    for (int i = 0; i < n; ++i) {
        if (visitado[i] || arrpos[i].second == i)
            continue;
        int tamano_ciclo = 0;
        int x = i;
        while (!visitado[x]) {
            visitado[x] = true;
            x = arrpos[x].second;
            tamano_ciclo += 1;
        }
        if (tamano_ciclo > 0)
            intercambios += (tamano_ciclo - 1);
    }
    return intercambios;
}

int min_intercambios(int n, vector<int>& zapatos_derechos, vector<int>& zapatos_izquierdos) {
    int intercambios_derechos = contar_intercambios(zapatos_derechos);
    int intercambios_izquierdos = contar_intercambios(zapatos_izquierdos);
    return intercambios_derechos + intercambios_izquierdos;
}

int main() {
    ios_base::sync_with_stdio(false);
cin.tie(NULL);

    int n;
    cin >> n;
    vector<int> zapatos_derechos(n), zapatos_izquierdos(n);

    for (int i = 0; i < n; ++i) {
        cin >> zapatos_derechos[i];
    }

    for (int i = 0; i < n; ++i) {
        cin >> zapatos_izquierdos[i];
    }

    cout << min_intercambios(n, zapatos_derechos, zapatos_izquierdos) << endl;

    return 0;
}
