#include <bits/stdc++.h>

using namespace std;

int main()
{

    long double n;
    int c=0;

    cin>>n;

    while(n>1){

        n=n/2;
        c++;
    }

    cout<<c+1<<"\n";

    return 0;
}
