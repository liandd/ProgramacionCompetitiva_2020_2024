#include <bits/stdc++.h>

using namespace std;

string limpiar(string cadena){
    string cadenaLimpia ="";

    for(int i = 0; i < cadena.length(); i++)
        if(cadena[i] != ' ') 
        cadenaLimpia.push_back(cadena[i]);
        
    return cadenaLimpia;
}

int main()
{
    string parentesis;
    getline(cin, parentesis);
    
    parentesis = limpiar(parentesis);
    
    int nivel = 0, complejidad = 0;
    while(parentesis != ""){
        nivel++;
        int parentesisEncontrados = 0;
        for(int i = 0; i < parentesis.length()-1; i++)
            if(parentesis[i] == '(' && parentesis[i+1] == ')'){
                parentesisEncontrados++;
                parentesis[i] = parentesis[i+1] = ' ';
            }
        
        complejidad += parentesisEncontrados * nivel;
        parentesis = limpiar(parentesis);
    }
    
    cout<<complejidad<<endl;
    
    return 0;
}
