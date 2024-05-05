#include <bits/stdc++.h>
using namespace std;

void salir(){
    cout<<0<<"\n";
    exit(0);
}

long long parseNumber(string& f){
    int tam = f.length();
    long long num = 0, actual = 1;
    for(int i = tam - 1; i >= 0; i--){
        long long aux = f[i] - '0';
        num += actual * aux;
        actual *= 10;
    }
    return num;
}

int main(){
    vector<string> f;
    vector<long long> nums;
    string aux;
    while(cin>>aux){
        f.push_back(aux);
    }
    
    vector<long long> numeros;
    for(auto& n : f){
        if(n.length() > 10) salir();
        for(char c : n){
            if(c > '9' || c < '0') salir();
        }
        
        if(n[0] == '0') salir();
        numeros.push_back(parseNumber(n));
    }
    
    if(
        numeros.size() != 3 ||
        (numeros[0] < 3 || numeros[0] > 1e9) ||
        (numeros[0] % 2 != 0) ||
        (numeros[1] + numeros[2] != numeros[0]) ||
        (numeros[1] == 1 || numeros[2] == 1)
    ) salir();
    for(long long i = 2; i*i <= numeros[1]; i++) if(numeros[1] % i == 0) salir();
    for(long long i = 2; i*i <= numeros[2]; i++) if(numeros[2] % i == 0) salir();
    cout<<1<<'\n';
    return 0;
}