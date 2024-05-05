#include <bits/stdc++.h>
using namespace std;


int main() {
    //ios::sync_with_stdio(false);
    //cin.tie(NULL);

    string a,b;
    cin>>a>>b;
    
    vector <string> cadenas;

    for(int i = 0; i < a.length(); i++ ){
        for(int j = 0; j <= b.length(); j++ ){
            string cadenaAgregar = "";
                for(int k = 0; k < b.length(); k++ ){
                    if(k == j)
                        cadenaAgregar.push_back(a[i]);
                    cadenaAgregar.push_back(b[k]);
                }
            if((j+1) > b.length())
            cadenaAgregar.push_back(a[i]);
            cadenas.push_back(cadenaAgregar);
        }
    }
    
    for(int i = 0; i < b.length(); i++ ){
        string cadenaEliminar = "";
        for(int j = 0; j < b.length(); j++ ){
            if(j!= i)
            cadenaEliminar.push_back(b[j]);
        }
        cadenas.push_back(cadenaEliminar);
    }
    
    for(int i = 0; i < a.length(); i++ ){
        for(int j = 0; j < b.length(); j++ ){
            string cadenaCambiar = b;
            cadenaCambiar[j] = a[i];
            cadenas.push_back(cadenaCambiar);
        }
    }
    
    sort(cadenas.begin(), cadenas.end());

    string temp = "";
    for(int j = 0; j < cadenas.size(); j++ ){
        if(temp != cadenas[j] && b != cadenas[j])
            cout<<cadenas[j]<<'\n';
        temp = cadenas[j];
    }
    
    return 0;
}