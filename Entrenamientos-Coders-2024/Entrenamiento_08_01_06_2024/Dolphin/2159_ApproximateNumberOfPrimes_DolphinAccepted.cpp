#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;
    double p, m;
    p = n/log(n);
    m = 1.25506*(p);
    cout<<fixed<<setprecision(1)<<p<<" "<<fixed<<setprecision(1)<<m<<"\n";
    return 0;
}

