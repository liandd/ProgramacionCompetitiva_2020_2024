#include<bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;

int fact(int n){
    for(int i=n-1; i>0; i--){
        n*=i;
    }
    return n;
}


int main(){
    int n=0;
    cin>>n;

    int a[n];
    int b[n];

    for(int i=0; i<n; i++){
        cin>>a[i];
    }

    for(int i=0; i<n; i++){
        cin>>b[i];
    }

    int per=fact(n);

    //int r=n-1;
    //int per2=fact(n-r);
    //cout<<per;
    //int h=(per/per2);

    int h1=0;
    if((n-2)==0){
        h1=per/((n-1)*n);
    }else{
        h1=(per/((n-2)*n));
    }

    cout<<h1<<"\n";

    return 0;
}
