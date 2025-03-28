#include<bits/stdc++.h>
using namespace std;
int main(){
    int t=0;
    cin>>t;

    int ar[t];

    for(int i=0; i<t; i++){
        cin>>ar[i];
    }
    int c2=0, c3=0, c4=0, c5=0;
    for(int i=0; i<t; i++){
        if(ar[i]%2==0){
            c2++;
        }
        if(ar[i]%3==0){
            c3++;
        }
        if(ar[i]%4==0){
            c4++;
        }
        if(ar[i]%5==0){
            c5++;
        }
    }

    cout<<c2<<" Multiplo(s) de 2\n";
    cout<<c3<<" Multiplo(s) de 3\n";
    cout<<c4<<" Multiplo(s) de 4\n";
    cout<<c5<<" Multiplo(s) de 5\n";

    return 0;
}
