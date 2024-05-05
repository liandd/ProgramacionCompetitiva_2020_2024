#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int T;
    cin>>T;
    while(T--){
        unsigned long long salida = 0;
        int n, m;
        cin>>n>>m;
        if(n <= m){
            int formula = (m*(m + 1))/2;
            for(int i = 0; i < n; i++)
                salida += ((formula % 1000000007) * ( (i + 1) % 1000000007)) % 1000000007;
        }else{
            int formula = (n*(n + 1))/2;
            for(int i = 0; i < m; i++)
                salida += ((formula % 1000000007) * ( (i + 1) % 1000000007)) % 1000000007;
        }
        cout<<salida<<"\n";
    }
}
