/**************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

***************************/

#include <bits/stdc++.h>

using namespace std;

int main()
{
    long long n,v,c;
    
    while(cin>>n and n!=0){
        
        v=sqrt(n);
        
        for(int i=1;i<=v;i++){
            
            c=pow(i,2);
            cout<<c;
            
            if(i<v){
                cout<<" ";
            }
        }
        cout<<"\n";
    }

    return 0;
}