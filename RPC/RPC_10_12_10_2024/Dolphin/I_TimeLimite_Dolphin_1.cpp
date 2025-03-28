/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <bits/stdc++.h>

using namespace std;





int main()
{
    
    int n,r,a,b,t=0,m;
    char c;
    vector<int>v;
    
    cin>>n>>r;
    
    
    for(int i=0;i<r;i++){
        
        cin>>c;
        
        if(c=='A'){
            
            cin>>a>>b;
            
            for(int j=0;j<v.size();j++){
                
                if(v[j]>=a and v[j]<=b){
                    
                    t++;
                }
            }
            
            m=(b-a+1)-t;
            cout<<m<<"\n";
            t=0;
        }
        
        if(c=='R'){
            cin>>a;
            
            v.push_back(a);
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



