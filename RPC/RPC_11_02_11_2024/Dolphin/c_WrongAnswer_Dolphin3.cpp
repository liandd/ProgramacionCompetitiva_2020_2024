#include<bits/stdc++.h>
using namespace std;

int p(char c){
    switch(c){
        case 'I':
            return 1;
            break;
        case 'V':
            return 5;
            break;
        case 'X':
            return 10;
            break;
        case 'L':
            return 50;
            break;
        case 'C':
            return 100;
            break;
        case 'D':
            return 500;
            break;
        case 'M':
            return 1000;
            break;
    }
    return 0;
}

int main (){
char m;
int n,r=0;
string cad;
cin>>n;
while(n--){
    cin>>cad;
    m=cad[cad.size()-1];
    r = p(m);
    for(int i = cad.size()-2;i>=0;i--){

        if(p(m)>=p(cad[i])){
            r=r-p(cad[i]);
        }else{
            r=r+p(cad[i]);
            m =cad[i];
        }
    }
    cout<<r<<"\n";
}


}
