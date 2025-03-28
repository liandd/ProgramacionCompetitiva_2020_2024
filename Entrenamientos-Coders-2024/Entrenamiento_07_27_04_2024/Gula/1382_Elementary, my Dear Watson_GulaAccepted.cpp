/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <bits/stdc++.h>

using namespace std;

int movientos (vector <int>& v) //& para que no lo modifique 
{
    int x= v.size();
    int cont=0;
    
    for (int i = 0; i < x; i++) {
        while (v[i] != i + 1) { 
            swap(v[i], v[v[i] - 1]);
            cont++;
        }
    }

    return cont;
}


int main (){
    
    int x, z;
    cin>>x;
       
    while(x--){
        
        int n=0;
        cin>>n;
        vector <int> s;
        for(int j=0; j<n; j++){
            cin>>z;
            s.push_back(z);
        }
        
        int  r= movientos(s);
        
        cout<<r<<"\n";
    }
}//2 1 4 5 3