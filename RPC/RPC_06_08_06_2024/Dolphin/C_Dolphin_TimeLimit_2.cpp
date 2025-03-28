
#include <bits/stdc++.h>

using namespace std;

int main()
{
    long n,r,t,c=1,v,a;
    
    cin>>n;
    
    while(n--){
        
        cin>>r>>t;
        
        if(r>t){
            a=t;
        }
        else{
            a=r;
        }
        
        
        if(t==1){
            	c=r;
    	}
    	else{
        
        
        for(int i=2;i<=a;i++){
            
            v=t/i;
            
    

    		
                if((i*v+1)==t){
                    
                    c++;
                
                
            }
        }
    	}
        
        cout<<c<<"\n";
        c=1;
        
    }

    return 0;
}
