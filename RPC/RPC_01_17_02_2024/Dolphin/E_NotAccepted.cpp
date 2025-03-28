/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <bits/stdc++.h>

using namespace std;


int main()
{
    
    double n1,n2,r;
    
    cin>>n1>>n2;
    
    if(n1>n2){
        
        r=(n1/n2)*2;
        cout<<fixed<<setprecision(16)<<r<<"\n";
    }
    else if(n2>n1){
        
        r=((n1/n2)/2);
        cout<<fixed<<setprecision(16)<<r<<"\n";
    }
    else{
        
        r=n1/n2;
        cout<<fixed<<setprecision(16)<<r<<"\n";
    }
    

    return 0;
}

