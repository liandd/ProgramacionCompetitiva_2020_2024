#include <bits/stdc++.h>
using namespace std;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin>>n;
    vector <int> numeros(n);
    
    vector <int> prefixIzq(n);
    vector <int> prefixDer(n);
    for(int i = 0; i < n; i++) cin>>numeros[i];
    
    sort(numeros.begin(), numeros.end());
    
    if(numeros.size() == 2){
        cout<<numeros[0]<<'\n';
        return 0;
    }
    
    prefixIzq[0] = numeros[0];
    prefixDer[n - 1] = numeros[n - 1];
    for(int i = 1; i < n; i++){
        prefixIzq[i] += prefixIzq[i - 1] +  numeros[i];
        prefixDer[n - 1 - i] += prefixDer[n - i ] +  numeros[ n - 1 - i];
    } 
    
    
    for(int i = 1; i < n - 1; i++){
        if(prefixIzq[i] == prefixDer[i]){
            cout<<numeros[i]<<'\n';
            return 0;
        }else if(prefixIzq[i] == prefixDer[i + 1] && prefixDer[i] == prefixIzq[i + 1]){
            cout<<numeros[i]<<'\n';
            return 0;
        }else if(prefixIzq[i] == prefixDer[i + 1]){
            cout<<numeros[i] + 1<<'\n';
            return 0;
        }
    }

    return 0;
}
