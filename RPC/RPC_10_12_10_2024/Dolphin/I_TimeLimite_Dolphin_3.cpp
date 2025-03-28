/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <bits/stdc++.h>

using namespace std;
int main()
{

    int n,r,t,a,b;
    char c;
    
    cin>>n>>r;


    vector<int>v(n,1);
    
    for(int i=0;i<r;i++){
        
        cin>>c;
        
        if(c=='A'){
                
            cin>>a>>b;
            
            t=count(v.begin()+a-1,v.begin()+b,1);
            
            cout<<t<<"\n";
        }
        
        if(c=='R'){
            cin>>a;
            
            v[a-1]=0;
        }
        
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
    

    return 0;
}
