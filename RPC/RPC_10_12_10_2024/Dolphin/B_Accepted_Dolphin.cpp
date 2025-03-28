#include <bits/stdc++.h>
using namespace std;

int main()
{
    string cad;
    map<char,int>mapa;
    cin>>cad;
    for(int i = 0; i < cad.size();i++){
        if(cad[i]!='-'){
        mapa[cad[i]]++;
        }
    }
    
    cout<<mapa.size()<<"\n";
    return 0;
}
