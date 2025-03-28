#include<bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(0);
#define MOD 1000000007
using namespace std;
int main(){
    //fast
    int n=0, q=0;
    cin>>n>>q;

    vector<long long int> fb(n);
    fb[0]=0;
    fb[1]=1;
    for(int i=2; i<n; i++){
        fb[i]=(fb[i-1]+fb[i-2])%MOD;
    }

    vector<long long int> L(n+1);
    L[0]=0;
    L[1]=1;
    for(int i=2; i<=n; i++){
        L[i]=(L[i-1]+L[i-2]+ fb[i])%MOD;
    }

    for(int i=0; i<q; i++){
        int s=0, t=0;
        cin>>s>>t;
        int h=t-s+1;

        cout<<((L[h]-fb[h]%MOD)+ MOD)%MOD<<"\n";

    }
    return 0;
}
