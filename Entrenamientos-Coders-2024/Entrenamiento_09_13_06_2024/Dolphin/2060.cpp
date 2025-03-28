#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n,d,c2=0,c3=0,c4=0,c5=0;
    cin>>n;
    int v[n];

    while(n-- and cin>>d){

        if(d%2==0){
            c2++;
        }
        if(d%3==0){
            c3++;
        }
        if(d%4==0){
            c4++;
        }
        if(d%5==0){
            c5++;
        }
    }

    cout<<c2<<" Multiplo(s) de 2\n";
    cout<<c3<<" Multiplo(s) de 3\n";
    cout<<c4<<" Multiplo(s) de 4\n";
    cout<<c5<<" Multiplo(s) de 5\n";

    return 0;
}
