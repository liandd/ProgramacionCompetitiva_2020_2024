

#include <bits/stdc++.h>

using namespace std;

int main()
{
    
    int a,k,d,A,K,l1,l2;
    bool juanes=false;
    
    cin>>d>>A>>K;
    
    l1=d/A;
    l2=d/K;
    
    for(int i=1;i<=l1;i++){
        
        for(int j=1;j<=l2;j++){
            
            if(((i*A)+(j*K))==d){
                
                juanes=true;
                
                break;
            }
        }
        
        if(juanes==true){
            break;
        }
    }
    
    if(juanes==true){
        
        cout<<"1\n";
    }
    else{
        cout<<"0\n";
    }
  
    

    return 0;
}

