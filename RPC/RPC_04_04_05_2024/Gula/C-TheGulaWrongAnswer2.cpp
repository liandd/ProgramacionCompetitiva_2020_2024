#include <bits/stdc++.h>
using namespace std;
int main() {
    int x;
    cin>>x;
    
    int v[x]; 
    vector <int> r;
    for(int i=0; i<x; i++){
        cin>>v[i];
    }
    int cont=1; 
    int aux=1;
    
    for(int i=0; i<x; i++){
        if(v[i]> v[i-1]){
            cont++;
        }else{
            aux=max(aux, cont);
            cont=1;
        }
        
        aux=max(cont, aux);
        
    }
    
    cout<<aux<<"\n";
    
    return 0;
}
