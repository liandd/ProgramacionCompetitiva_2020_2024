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
    
    
    cin>>n>>r;
    vector<int>v(n,0) ;

    for(int i=0;i<r;i++){
        
        cin>>c;
        
        if(c=='A'){
                
            cin>>a>>b;
            
            for(int j=a-1;j<=b-1;j++){
                
                if(v[j]!=1){
                    
                    t++;
                }
            }
            
            //m=(b-a+1)-t;
            cout<<t<<"\n";
            t=0;
        }
        
        if(c=='R'){
            cin>>a;
            
            v[a-1]=1;
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



