#include<bits/stdc++.h>
using namespace std;

int main(){
    int n=0, m=0;
    cin>>n>>m;
    vector<int>a(n);
    vector<int>items;

    for(int i=0; i<n; i++){
        cin>>a[i];
    }//for

    sort(a.begin(), a.end());

    a.push_back(0);

    for(int i=0; i<n; i++){
        int aux = a[i]+a[i+1];
        items.push_back(aux);
        i++;
    }//for

    sort(items.begin(), items.end());

    cout<<items[0]<<"\n";

    return 0;
}
