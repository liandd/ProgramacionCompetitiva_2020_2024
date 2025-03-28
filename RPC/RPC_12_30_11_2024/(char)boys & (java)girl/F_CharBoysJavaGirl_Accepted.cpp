#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n=0,maximo=-1;
    bool ban = true;
    string p;
    cin>>n;
    map<string, int>mapa;
    for(int i =0;i<n;i++){
        string aux;
        cin>>aux;
        mapa[aux]=i;
    }
     for(int i =0;i<n;i++){
        string aux;
        cin>>aux;
        if(mapa[aux] != i){
            ban = false;
        }
        if( mapa[aux]-i>maximo){
            maximo=mapa[aux]-i;
            p = aux;
        }else if (mapa[aux]-i==maximo){
            maximo=mapa[aux]-i;
        }
    }
    if(ban == false){
        cout<<p<<"\n";
    }else{
        cout<<"suspicious\n";
    }


    return 0;
}
