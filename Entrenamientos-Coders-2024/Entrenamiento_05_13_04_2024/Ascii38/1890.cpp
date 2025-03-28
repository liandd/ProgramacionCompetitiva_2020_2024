#include <bits/stdc++.h>
using namespace std;

int main() {
    int t = 0;
    cin>>t;
    while(t--){
        int c=0,d=0;
        cin>>c>>d;
        if(c==0 && d==0) {
            printf("%d\n",0);
        }else{
            long long r = pow(26,c)*pow(10,d);
            printf("%lld\n", r);
        }
        
    }
    return 0;
}