#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    long d,c=0;

    cin>>n;

    while(n-- and cin>>d){

        for(int i=1;i<d;i++){

            if(d%i==0){
                c=c+i;
            }
        }



        if(c==d){
            cout<<d<<" eh perfeito\n";
        }
        else{
            cout<<d<<" nao eh perfeito\n";
        }

        c=0;
    }

    return 0;
}
