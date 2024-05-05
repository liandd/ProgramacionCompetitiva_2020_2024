#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    vector<string> cadenas(n);
    
    string cadenaMin;
    for(int i = 0; i < n; i++){
        cin>>cadenas[i];
        if(i == 0) cadenaMin = cadenas[i];
        else cadenaMin = min(cadenaMin, cadenas[i]);
    }
    
    
    string salida = "";
    for(int i = 0; i < cadenaMin.size() ; i++){
        for(int j = 1; j <= cadenaMin.size(); j++){
            string posibleSubs = cadenaMin.substr(i, j);
            bool verificar = true;
            for(int k = 0; k < n; k++){
                if(cadenas[k].find(posibleSubs) == string::npos){
                    verificar = false;
                    break;
                }
            }
            if(verificar) 
                salida = (salida.size() < posibleSubs.size() ? posibleSubs : salida);
        }
    }
    
    cout<<salida.size()<<"\n";
    return 0;
}
