#include<bits/stdc++.h>
using namespace std;
int main(){
    int n=0;
    cin>>n;

    double m=n/log(n);
    double p=1.25506*m;

    cout<<fixed<<setprecision(1)<<m<<" "<<fixed<<setprecision(1)<<p<<"\n";

    return 0;
}
