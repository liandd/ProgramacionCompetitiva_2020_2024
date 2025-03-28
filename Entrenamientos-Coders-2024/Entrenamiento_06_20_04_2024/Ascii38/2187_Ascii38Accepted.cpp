//2187 - Bits Exchanged: 
#include <bits/stdc++.h>
using namespace std;

int main(){
    int n =0;
    int cont=1;
    while(cin>>n && n){
        cout<<"Teste "<<cont++<<"\n";
        cout<<n/50<<" ";
        n%=50;
        cout<<n/10<<" ";
        n%=10;
        cout<<n/5<<" ";
        n%=5;
        cout<<n<<"\n\n";
    }
    return 0;
}