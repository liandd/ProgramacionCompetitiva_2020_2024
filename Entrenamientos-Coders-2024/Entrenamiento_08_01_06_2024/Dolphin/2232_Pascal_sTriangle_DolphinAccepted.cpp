#include <bits/stdc++.h>
using namespace std;

int main()
{

    int n,t;
    cin>>n;
    while(n--){
       cin>>t;
       t = pow(2,t);
       cout<<t-1<<"\n";
    }
}
