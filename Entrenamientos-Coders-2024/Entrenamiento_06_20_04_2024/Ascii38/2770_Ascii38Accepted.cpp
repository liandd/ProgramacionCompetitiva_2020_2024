//2770 - Board Size:
#include <bits/stdc++.h>
using namespace std;
#define lli long long int
int main() {
    ios_base::sync_with_stdio(0);
    lli a =0,b=0,c=0,d=0,cont=0;
    while(cin>>a>>b>>cont){
        while(cont--){
            cin>>c>>d;
            if((c<=a && d<=b) || (c<=b && d<=a)){
                cout<<"Sim\n";
            }
            else cout<<"Nao\n";
        }
    }
    return 0;
}