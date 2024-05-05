#include <bits/stdc++.h>
using namespace std;

int main(){
    long long n;
    cin>>n;
    long long salida = 0, maximo = 0, minimo = 1 + 10e9;
    for(int i = 0; i < n; i++){
        long long aux;
        cin>>aux;
        maximo = max(maximo, aux);
        minimo = min(minimo, aux);
        salida += aux;
    }

    salida += abs(maximo - minimo);

    cout<<salida<<'\n';
    return 0;
}
