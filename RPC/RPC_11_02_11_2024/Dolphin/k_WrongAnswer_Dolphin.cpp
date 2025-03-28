#include <bits/stdc++.h>
using namespace std;

int main(){
    long long int p=0, n=0;
    cin>>p>>n;

    if(n>1000000000){
        cout<<0<<"\n";
    }else{
        n*=n;
        cout<<max(p-n,(long long int) 0)<<"\n";
    }

    return 0;
}
