#include <bits/stdc++.h>
using namespace std;

int main()
{
    
    int n,d,pm=0;
    
    cin>>n>>d;
    
    int v[n];
    
    for(int i=0;i<n;i++){
        
        cin>>v[i];
    }
    
    for(int i=0;i<n-1;i++){
        
        for(int j=i+1;j<=d+i;j++){

            
            if(j<n){

                if((v[j]-v[i])>pm){
             
                pm=v[j]-v[i];
            }
            }
            
            
        }
    }
    
cout<<pm<<"\n";
    
    return 0;
}