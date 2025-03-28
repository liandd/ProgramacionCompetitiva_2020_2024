
#include <bits/stdc++.h>

using namespace std;


int main()
{
    
    int n,r,a,b,t=0,m, hi,hf;
    char c;
    //vector<int>v;
    set<int>v;
    
    cin>>n>>r;
    
    
    for(int i=0;i<r;i++){
        
        cin>>c;
        
        if(c=='R'){
            cin>>a;
            
        	v.insert(a);
        }
        
        if(c=='A'){
            
            cin>>hi>>hf;
            t=0;
            for(a=hi;a<=hf;a++){
                
                if (v.find(a) == v.end()) {
                    t++;
                }
            }
            
            cout<<t<<"\n";
        }
        
        
        
    }
    
	return 0;
} 
    



/*20 8
A 5 10
R 6
R 9
R 3
A 5 10
R 13
R 18
A 1 20*/



