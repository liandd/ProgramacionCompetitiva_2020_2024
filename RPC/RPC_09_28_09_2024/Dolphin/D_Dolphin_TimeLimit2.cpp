#include <bits/stdc++.h>
using namespace std;

int main()
{
    
    int n,d,pm=0,i,j;
    
    cin>>n>>d;
    
    if(d>n){
        
        d=n-1;
    }
    
    int v[n];
    
    for(i=0;i<n;i++){
        
        cin>>v[i];
        
        if(i>=d){
            
            for(j=i;j>i-d;j--){
                
                /*cout<<v[j]<<" "<<v[i-d]<<endl;
                cout<<i<<" "<<j<<endl;
                cout<<endl;*/
                
                if((v[j]-v[i-d])>pm){
                    pm=v[j]-v[i-d];
                }
            }
        }
    }
    //cout<<i<<"---------------------"<<endl;
    i=i-1;

     while(d--){   
    
            for(j=i;j>i-d;j--){
                
                /*cout<<v[j]<<" "<<v[i-d]<<endl;
                cout<<i<<" "<<j<<endl;
                cout<<endl;*/
                
                if((v[j]-v[i-d])>pm){
                    pm=v[j]-v[i-d];
                }
            }
    }
    
    
    
    
cout<<pm<<"\n";
    
    return 0;
}