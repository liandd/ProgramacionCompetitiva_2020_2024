#include<bits/stdc++.h>
using namespace std;
int main(){
    int n=0, w=0;
    cin>>n>>w;

    vector<int> ar(n);

    for(int i=0; i<n; i++){
        cin>>ar[i];
    }

    sort(ar.rbegin(), ar.rend());
    /*for(int i=0; i<n; i++){
        if(ar[w-1]==ar[w]){
            cout<<"no\n";
            return 0;
        }
        if(w+w<=n){
            w+=w;
        }else{
            break;
        }
    }*/
    for(int i=0; i<n-w; i++){
        if(ar[i]<=ar[w+i]){
            cout<<"no\n";
            return 0;
        }
    }

    cout<<"yes\n";
    return 0;
}
