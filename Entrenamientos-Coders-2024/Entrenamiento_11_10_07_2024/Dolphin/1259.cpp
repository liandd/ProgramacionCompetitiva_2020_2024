#include <bits/stdc++.h>
using namespace std;

int main (){
    int n,a,i = 0;
    vector<int>pares ;
    vector<int>impares;

    cin>>n;

    for(i = 0;i < n;i++){
        cin>>a;
        if(a % 2 == 0){
            pares.push_back (a);
        }else{
            impares.push_back(a);
        }
    }
    sort(pares.begin(), pares.end());
    sort(impares.rbegin(),impares.rend());

    for( i= 0 ; i < pares.size(); i++){
        cout<<pares[i]<<"\n";
    }
    for(i = 0;i < impares.size(); i++){
        cout<<impares[i]<<"\n";
    }
    return 0;
}
