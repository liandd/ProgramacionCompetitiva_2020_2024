/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <bits/stdc++.h>

using namespace std;

int main()
{
    unsigned long long n,l,a,b,p;
    bool malaquias=true;
    cin>>l>>n;
    unsigned long long v[n];
    
    for(int i=0;i<n;i++){
        
        cin>>v[i];
        p=v[i];
        
        if(i>0 and malaquias==true){
            
            for(int j=0;j<=i;j++){
                
                if(p*v[j]==l){
                   
                 a=p;
                 b=v[j];
                 malaquias=false;
                 break; 
                }
            }
            
        }
    }
    

    
    if(a<b){
        cout<<a<<" "<<b<<"\n";
    }
    else{
        cout<<b<<" "<<a<<"\n";
    }
    

    return 0;
}

