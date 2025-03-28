/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <bits/stdc++.h>

using namespace std;

int main()
{
    int x,y,n,c1=0,c2=0;
    string p;
    cin>>x>>y>>n;
    char m[x][y];
    
    for(int i=0;i<x;i++){
        
        for(int j=0;j<y;j++){
            
            cin>>m[i][j];
            
            if(m[i][j]!='X'){
                
                c1++;
            }
        }
    }
    
    for(int i=0;i<n;i++){
        
        cin>>p;
        c2=c2+p.size();
    }
    
    if(c1==c2){
        cout<<c1<<"\n";
    }
    else{
        cout<<"impossible\n";
    }
    
    return 0;
}