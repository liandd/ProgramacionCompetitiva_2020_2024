#include<bits/stdc++.h>
using namespace std;
int main(){
    unsigned long long n=0;
    cin>>n;
    unsigned long long ar[n];
    unsigned long long ar2[n];
    unsigned long long m=0;
    for(int i=0; i<n; i++){
        cin>>ar[i]>>ar2[i];
        unsigned long long w=ar[i]*ar2[i]*min(ar[i], ar2[i]);
        if(m<w){
            m=w;
        }
    }
    cout<<m<<"\n";

    return 0;
}
