#include<bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;
int main(){
    fast
    int n=0, t=0, a=0, b=0, c=0;
    cin>>n>>t;
    char l;
    vector<bool> d(n+1, true);
    for(int i=0; i<t; i++){
        cin>>l;
        if(l=='A'){
            cin>>a>>b;
            int cont=0;
            for(int j=a; j<=b; j++){
                if(d[j]==true){
                    cont++;
                }
            }
            cout<<cont<<"\n";
        }else{
            cin>>c;
            d[c]=false;
        }
    }

    return 0;
}
