#include <bits/stdc++.h>

using namespace std;

int main(){                          
    //2201022110222212220
    //10212012012102121210210
    string cad;
    long long int sum=0,ant=0,res=0,alm=0,alm2=0,r=0;
    cin>>cad;
    
    for(int i=0;i<cad.size();i++){             
        
        if(cad[i]=='0'){   
                res=ant+sum;
                alm=alm+res;
                ant=ant+sum;
                sum=0;
            
        
        }
        else{
            sum++;
        }
        
        
    }
    
    res=0;
    sum=0;
    ant=0;
    
    
    for(int i = 0; i< cad.size();i++){
        if(cad[i]=='0'){
            continue;
        }else if(cad[i]=='1'){
             res=ant+sum;
                alm2=alm2+res;
                ant=ant+sum;
                sum=0;
          
        }
        else{
            sum++;
        }
            
        
    }
    r=alm+alm2;
    cout<<r<<"\n";

    return 0;
}
