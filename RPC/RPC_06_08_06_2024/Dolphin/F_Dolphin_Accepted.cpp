
#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, p,m=0,b;
    
    cin>>n>>p;
    
    while(n--){
        
        cin>>b;
        
        if(b<=p){
            
            if(b>m){
                
                m=b;
            }
        }
    }
    
    cout<<m<<"\n";

    return 0;
}
