#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
#include<math.h>
using namespace std;
int main(){
    
    long long n=1,k=2,k2=1,p=1,np=0,c=0,c2=0;
    string s="";
    
    np=((k+1)*k);
    
    for(long long i=0;i<n;i=i+1){
      if(i<k){
        s=s+"0";
        p=p+1;
      }else{
       if(n-i<k){
         s=s+"1";
         c=c+1;
       }else{
       if(k2<=np){
        k2=k2+1;
       if(p<=k){
         s=s+"0";
         p=p+1;
       }else{
        s=s+"1";
        p=1;
        c=c+1;
       }
       }else{
        s=s+"0";
        k2=1;
        //c=c+1;
       }
       }
      }

    }

   
   
    //cout<<s<<"\n";
    cout<<c<<"\n";





    return 0;
}