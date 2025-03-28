#include <bits/stdc++.h>
using namespace std;

int main()
{
   
   int n;
   bool j1=true,j2=false;
   
   cin>>n;
   
   for(int i=1;i<=n;i++){
       
       if(n%i==0){
           
           if(j1==true){
               j1=false;
               j2=true;
           }
           
           else if(j2==true){
               j2=false;
               j1=true;
           }
       }
       
   }
   
   if(j1==true){
       cout<<"Y\n";
   }
   else{
       cout<<"N\n";
   }
   
   
}

