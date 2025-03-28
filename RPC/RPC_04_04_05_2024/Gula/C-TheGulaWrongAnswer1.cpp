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
    int cont=1, aux=0;

    for(int i=1; i<x; i++){
        if(v[i-1]<v[i]){
            cont++;
        }else{
            if(cont> aux){
            aux=cont;
            }
            cont=1;

        }

    }

    cout<<aux<<"\n";

    return 0;
}
