#include<bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;
int main(){
    fast
    int n=0, m=0;
    cin>>n>>m;

    int ar[n];
    for(int i=0; i<n; i++){
        cin>>ar[i];
    }

    int ma=0;
    for(int i=0; i<n; i++){
        for(int j=i+1; j<i+m && j<n; j++){
            if(ar[j]-ar[i]>ma){
                ma=ar[j]-ar[i];
            }
        }
    }
    cout<<ma<<"\n";

    return 0;
}
