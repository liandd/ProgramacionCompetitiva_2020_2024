#include<bits/stdc++.h>
using namespace std;
int main(){
    long long int n=0;
    cin>>n;
    
    if(n==3){
        cout<<0<<"\n";
    }else{
        long long int h=n-3;
        
        h=h+((h*(h+1)/2));
        
        cout<<h<<"\n";
    }

    return 0;
}