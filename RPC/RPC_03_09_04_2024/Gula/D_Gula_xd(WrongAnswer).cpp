#include <bits/stdc++.h>
using namespace std;

bool esPri(int n){
    if(n<1){
        return false;
    }else{
        for(int i=2; i<sqrt(n); i++){
            if(n%i==0){
                return false;
            }
        }
    }
    
    return true;
}

int main()
{
    int x;
    
    cin>>x;
    
    if(esPri(x)){
        cout<<"N\n";
    }else{
        cout<<"Y\n";
    }
    
    
    return 0;
}

