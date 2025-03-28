/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <bits/stdc++.h>

using namespace std;

int main()
{
    unsigned long long n,l,a,b;

    cin>>l>>n;
    unsigned long long v[n];
    
    for(int i=0;i<n;i++){
        
        cin>>v[i];
        
    }
    
    
    for(int i=0;i<n;i++){
        
        for(int j=0;j<n;j++){
         
         if(i!=j){
             
             if(v[i]*v[j]==l){
                 
                 a=v[i];
                 b=v[j];
                 break;
             }
         }
            
        }
    }
    
    if(a<b){
        cout<<a<<" "<<b<<"\n";
    }
    else{
        cout<<b<<" "<<a<<"\n";
    }
    

    return 0;
}

