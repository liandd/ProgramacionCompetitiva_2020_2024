#include<bits/stdc++.h>
using namespace std;
int main(){
bool p, r, a;
int j1=0, j2=0, ganador=0;
cin>>p>>j1>>j2>>r>>a;
int suma = j1+j2;
if((suma%2==0 && p==1) || (suma%2==1 && p==0)) ganador = 1;
    else ganador = 2;
    if((r==1 && a==0) || (r==0 && a==1)) ganador = 1;
    else if(r==1 && a==1) ganador=2;

    cout<<"Jogador "<<ganador<<" ganha!\n";
}
