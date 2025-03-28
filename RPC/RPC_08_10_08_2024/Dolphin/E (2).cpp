#include <bits/stdc++.h>
using namespace std;

int main()
{
    unsigned long long n, a, b;
    unsigned long long min=0, r=0, max=0;
    cin>>n;

    while(n--){
        min=0, r=0;
        cin>>a>>b;

        if(a<b){
            min=a;
        }else{
            min=b;
        }

        r = a*b*min;

        if(r>max){
            max=r;
        }

    }
    cout<<max<<"\n";
}
