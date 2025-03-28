#include<iostream>
#include<string>
#include<vector>
#include<utility>
#include<algorithm>
using namespace std;
int main(){
    long long  num=0,num2=0,k=0,k2=0;
    
    string roman;
    /*M    C    M     X   C   I  V
    1000  100  1000   10 100  1   5*/

    cin>>num2;

    while(num2--){
       
    long long  num=0,k=0,k2=0;
    
        cin>>roman;
        
    for(long long  i=(roman.size()-1);i>=0;i=i-1){

        switch(roman.at(i)){
            case 'I':num=1;
            break;
            case 'V':num=5;
            break;
            case 'X':num=10;
            break;
            case 'L':num=50;
            break;
            case 'C':num=100;
            break;
            case 'D':num=500;
            break;
            case 'M':num=1000;
            break;
        }
      
        if(k2>num){
            k=k-num;
        }else{
            k=k+num;
        }

        if(k2<num){
            k2=num;
        }

    }

    cout<<k<<"\n";

       
    
    }

    return 0;
}