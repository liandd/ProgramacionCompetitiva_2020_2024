#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<int> bills(6, 0);
    int vals[6] = {1, 5, 10, 20, 50, 100};
    int i = 0, cantidadMax = 0, valor = 0;
    while(cin>>bills[i++] && i < 6);
    for(i = 0; i < 6; i++)
        bills[i] *= vals[i];
    for (i = 0; i < 6; i++)
        if(bills[i] >= cantidadMax) {
            cantidadMax = bills[i];
            valor = vals[i];
        }
    cout<<valor<<endl;
    return 0;
}
