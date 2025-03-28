#include<bits/stdc++.h>

using namespace std;

int main(){
    int t, n;
    while(cin>>t){
        if(!t) return 0;
        while(t--){
            cin>>n;
            if(n%2==1) cout<<(n*2)-1<<endl;
            else cout<<(n*2)-2<<endl;
        }
    }

return 0;
}
