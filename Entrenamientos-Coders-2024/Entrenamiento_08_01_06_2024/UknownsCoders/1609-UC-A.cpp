#include<bits/stdc++.h>
using namespace std;
int main(){
    int t=0;
    cin>>t;
    while(t--){
        int n=0;
        cin>>n;
        vector<int> h(n);
        for(int i=0; i<n; i++){
            cin>>h[i];
        }
        sort(h.begin(), h.end());
        h.erase(unique(h.begin(), h.end()), h.end());

        int res=h.size();

        cout<<res<<"\n";
    }


 return 0;
}
