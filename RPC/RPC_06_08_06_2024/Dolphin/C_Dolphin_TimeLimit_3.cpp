
#include <bits/stdc++.h>

using namespace std;

int main()
{
    long long         n,r,t,c=1,v,a;
    
    cin>>n;
    
    while(n--){
        
        cin>>r>>t;
        
        
        
        if(t==1){
            	c=r;
    	}
    	else{
        
        
        for(int i=2;i<=((t/2)+1);i++){
            
            v=t/i;
                if((i*v+1)==t){
                    
                    c++;
                
                
            }
        }
        
        if(r>=t and t>4){
        	c++;
		}
    	}
        
        cout<<c<<"\n";
        c=1;
        
    }

    return 0;
}
