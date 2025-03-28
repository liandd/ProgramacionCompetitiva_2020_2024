/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n=0,c=1,m=0,a=0;
    cin>>n;
    int v=0;
    for(int i=0;i<n;i++){
       /* 6
5 7 2 4 6 3*/
        cin>>v;
        if(i==0){ a=v;  }
        if(v>a){ c++;  }
        else{ c=1;}
        if(c>m){ m=c;}
        a=v;
    }
    cout<<m<<"\n";
    return 0;
}

