/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <bits/stdc++.h>

using namespace std;

struct dato {
    int clave,valor;
};

bool cmp( dato a,  dato b){
        
        if(a.valor<b.valor){
            return true;
        }else if(a.valor>b.valor){
            return false;
        }else{
            if(a.clave<b.clave) return true;
            else return false;
        }
    }
    
int main()
{
    /*6 3
3
6
2
3
5
4*/  
    int n,k,sum=0,c;
	  
    cin>>n>>k;
    
    vector<dato>vec(n-k+1);
    int v[n];
    
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    
    for(int i=0;i<=n-k;i++){
        
        for(int j=1;j<=k;j++){
            c=i+j-1;
            sum=sum+(j*v[c]);
            
        }

        vec[i].valor=sum;   
        vec[i].clave=i+1;
        sum=0;
    }
    sort(vec.begin(),vec.end(),cmp);
    
    for(int i=0;i<=n-k;i++){
        
    cout<<vec[i].clave<<" "<<vec[i].valor<<"\n";



    }
  
    
    
    
    return 0;
}

