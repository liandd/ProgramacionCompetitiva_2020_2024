/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n,nm,mm=0,c=0,rm=0,in;
    cin>>n;
    int v[n];
    
    for(int i=0;i<n;i++){
        cin>>v[i];
        
        if(i==0){
            nm=v[i];
        }
        
        if(v[i]<nm){
            nm=v[i];
        }
        
        if(v[i]>mm){
            mm=v[i];
        }
        
    }
    
    in=nm;
   
    for(int j=in;j<=mm;j++){
    
        nm=j;
        c=0;
        for(int i=0;i<n;i++){
            
            if(v[i]>=j){
                c++;
            }
            else{
                
                if((j*c)>rm){
                    
                    //cout<<c<<" ";
                    rm=j*c;
                    //cout<<rm<<"gg";
                }
                //cout<<c<<" ";
                c=0;
            }
            
            if(i==n-1){
                
                if((j*c)>rm){
                    
           
                    rm=j*c;
                }
                c=0;
            }
        }
       
 
    }
    
     cout<<rm<<"\n";
/*    7
2 5 7 3 5
10 2*/

    
    
    return 0;
}