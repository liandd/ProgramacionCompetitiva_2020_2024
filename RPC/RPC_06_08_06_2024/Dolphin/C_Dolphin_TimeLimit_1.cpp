
#include <bits/stdc++.h>

using namespace std;

int main()
{
    long n,r,t,c=1,v;
    
    cin>>n;
    
    while(n--){
        
        cin>>r>>t;
        
        for(int i=2;i<=r;i++){
            
            v=t/i;
            
            if((i*v+1)==t){
                
                c++;
            }
            
        }
        
        cout<<c<<"\n";
        c=1;
        
    }

    return 0;
}
