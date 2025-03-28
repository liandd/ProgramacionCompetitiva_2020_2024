#include<bits/stdc++.h>
using namespace std;
int main(){
    int n=0, p=0;
    cin>>n>>p;

    vector<int> v(n);

    for(int i=0; i<n; i++){
        cin>>v[i];
    }

    int mayor=v[0];

    for(int i=0; i<n; i++){
        if(v[i]>mayor && p>=v[i]){
           mayor=v[i];
        }
    }

    cout<<mayor<<"\n";


    return 0;
}
