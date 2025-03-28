/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <bits/stdc++.h>

using namespace std;

int main()
{
    
    int n,c=0,m=0,a;
    cin>>n;
    int v;
    
    for(int i=0;i<n;i++){
        
        cin>>v;
        
        if(i==0){
          a=v;  
        }
        
        if(v>a){
            
            c++;
        }
        else{
            
            if(c>m){
                
                m=c;
                c=0;
            }
            
        }
        a=v;
    }
    
    cout<<m+1<<"\n";
  
    

    return 0;
}

