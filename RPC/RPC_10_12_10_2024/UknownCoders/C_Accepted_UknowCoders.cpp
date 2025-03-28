#include<bits/stdc++.h>
using namespace std;
int main(){
    int n=0, m=0;
    cin>>n>>m;
    vector<int> ar(n+1, 0);
    /*bool b1[n+1];
    bool b2[n+1];*/

    vector<bool> b1(n+1, true);
    vector<bool> b2(n+1, true);
    int p=0, l=0;
    for(int i=0; i<m; i++){
        cin>>p>>l;
        if(l==1 && b1[p]==true){
            ar[p]++;
            b1[p]=false;
        }else if(l==2 && b2[p]==true){
            ar[p]++;
            b2[p]=false;
        }
    }

    for(int i=1; i<=n; i++){
        if(ar[i]==2){
            cout<<i<<"\n";
        }
    }

    return 0;
}
