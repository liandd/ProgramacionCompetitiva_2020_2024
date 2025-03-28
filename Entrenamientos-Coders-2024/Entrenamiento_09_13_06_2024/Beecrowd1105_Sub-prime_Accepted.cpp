#include <bits/stdc++.h>

using namespace std;

int main(){
    bool posible;
    int saldos[21];
    int B, N, deudor, acreedor, valor;

    while(cin >> B >> N){
        if(!B && !N)    break;

        for(int i = 1; i <= B; ++i){
            cin >> saldos[i];
        }

        for(int i = 0; i < N; ++i){
            cin >> deudor >> acreedor >> valor;

            saldos[deudor] -= valor;
            saldos[acreedor] += valor;
        }

        posible = true;
        for(int i = 1; i <= B; ++i){
            if(saldos[i] < 0){
                posible = false;
                break;
            }
        }

        cout << (char) (posible ? 'S' : 'N') << endl;
    }

    return 0;
}
