/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <bits/stdc++.h>

using namespace std;


struct carlitos{
    
     int p;
     bool uno;
     bool dos;
};



int main()
{
    int n,r,a,b;
    
    cin>>n>>r;
    
    vector<carlitos>victor(n);
    
    
    for(int i=0;i<r;i++){
        
        cin>>a>>b;
        
        if(b==1){
            
            victor[a-1].uno=true;
        }
        
        if(b==2){
            
            victor[a-1].dos=true;
        }
        
    }
    
    for(int i=0;i<n;i++){

        if(victor[i].uno==true and victor[i].dos==true){
            
            cout<<i+1<<"\n";
        }
    }
   

    return 0;
}


/*3 11
1 1
1 1
3 1
3 1
3 1
2 2
1 2
2 1
3 1
2 3
2 2

4 5
1 3
1 2
3 2
3 1
4 3*/



