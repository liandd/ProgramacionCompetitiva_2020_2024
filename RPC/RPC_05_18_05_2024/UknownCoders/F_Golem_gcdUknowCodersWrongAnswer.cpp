#include<bits/stdc++.h>
using namespace std;
int main(){
    int n=0;
    cin>>n;

    vector<int> v(n);

    for(int i=0; i<n; i++){
        cin>>v[i];
    }

    sort(v.begin(), v.end());

    int aux=0;
    for(int i=v.size()-1; i>0; i--){
        if(v[i]!=v[i-1]){
            aux+=v[i];
        }else{
        	aux+=v[i];
            break;
        }
    }

    cout<<aux<<"\n";


    return 0;
}

