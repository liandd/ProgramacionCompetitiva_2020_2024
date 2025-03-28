#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9+7;

vector<long long> calcf(int n){
    vector<long long> F(n+1);
    vector<long long> aux(n+1);

    F[1]=1;

    for(int i=2; i<=n; i++){
        F[i] = (F[i-1] + F[i-2])%MOD;
        aux[i] = (F[i] + aux[i-1] + aux[i-2])%MOD;
    }
    return aux;

}

int main()
{
    vector<long long> aux2;
    int n,q,s,t;
    cin>>n>>q;

    aux2=calcf(n);

    while(q--){

        cin>>s>>t;
        cout<<aux2[t-s+1]<<"\n";

    }

    return 0;
}
