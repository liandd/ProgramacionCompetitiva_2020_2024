#include <bits/stdc++.h>
using namespace std;

struct punto{
    long long valor;
    int pos;
};

punto mayorJ(punto a, punto b){
    if(a.valor > b.valor)
        return a;
    else
        return b;
}

punto menorJ(punto a, punto b){
    if(a.valor < b.valor)
        return a;
    else
        return b;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    long long n, c;
    punto mayor, menor;
    mayor.valor = 0; menor.valor = 4 * 10e5 + 1;
    mayor.pos = 0; menor.pos = 0;
    cin>>n>>c;
    for(int i = 0; i < n; i++){
        punto aux;
        cin>>aux.valor;
        aux.pos = i + 1;
        if(i == 0)
            cout<<0<<" ";
        else {
            long long resp1 = abs(aux.valor - mayor.valor) - c * abs(aux.pos - mayor.pos);
            long long resp2 = abs(aux.valor - menor.valor) - c * abs(aux.pos - menor.pos);
            if(i == n - 1)
                cout<< max( resp1, resp2 )<<"\n";
            else
                cout<< max( resp1, resp2 )<<" ";
        }
        mayor = mayorJ(mayor, aux);
        menor = menorJ(menor, aux);

    }
    return 0;
}
