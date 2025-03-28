#include <bits/stdc++.h>
using namespace std;


int main() {
    int a, k, o;
    bool ban= false;
    cin>>o>>a>>k;
    
    
 	for(int i=1; i<o; i++){
        for(int j=1; j<o; j++){
            if(o== (a*i)+(k*j)){
                ban= true;
                break;
            }
        }
    }
    
    if(ban){
        cout<<"1\n";
    }else{
        cout<<"0\n";
    }
	
    return 0;
}
