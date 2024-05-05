#include<bits/stdc++.h>
using namespace std;

int main(){
    int ds,ys,dm,ym;
    cin>>ds>>ys>>dm>>ym;
    int s=ys-ds,m=ym-dm;
    int a=0;
    while(m!=0&&s!=0){ 
        a++;
        s--;
        m--;
        if(m==s&&(m==0&&s==0)){
            break;
        }
        if(s==0){
            s=ys;
        }
        if(m==0){
            m=ym;
        }
        
    }
    cout<<a<<"\n";
    
return 0;
}