#include <bits/stdc++.h>
using namespace std;

int main()
{
    
    int n,d,pm=0;
    
    cin>>n>>d;
    
    if(d>n){
        
        d=n-1;
    }
    
    int v[n];
    
    for(int i=0;i<n;i++){
        
        cin>>v[i];
        
        if(i>=d){
            
            for(int j=i;j>i-d;j--){
                
                /*cout<<v[j]<<" "<<v[i-d]<<endl;
                cout<<i<<" "<<j<<endl;
                cout<<endl;*/
                
                if((v[j]-v[i-d])>pm){
                    pm=v[j]-v[i-d];
                }
            }
        }
    }
    
cout<<pm<<"\n";
    
    return 0;
}