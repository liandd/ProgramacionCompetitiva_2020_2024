#include <bits/stdc++.h>
using namespace std;

int main(){
    string f;
    string salida = "";
    int puntero = 0;

    cin>>f;

    while(f[puntero] != 'U'){
        salida += "-";
        puntero++;
    }
    salida += "U";
    puntero++;

    int ultimaF = 0;
    for(int i = f.length() - 1; i >= 0; i--){
        if(f[i] == 'F'){
            ultimaF = i;
            break;
        }
    }

    while(puntero < ultimaF){
        salida += "C";
        puntero++;
    }
    salida += "F";
    puntero++;
    while(puntero < f.length()){
        salida += "-";
        puntero++;
    }

    cout<<salida<<endl;
    return 0;
}
