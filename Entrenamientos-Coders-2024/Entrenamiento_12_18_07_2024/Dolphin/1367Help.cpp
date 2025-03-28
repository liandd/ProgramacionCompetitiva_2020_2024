#include <bits/stdc++.h>
using namespace std;


int main() {
    
    int n,t,s=0,c=0,b=0;
    char l,d;
    string v;
    bool h=true;
    
    while(cin>>n and n!=0){
        
        while(n--){
            
            cin>>l>>t>>v;
            
            if(d!=l){
                d=l;
                h=true;
                c=0;
                if(v=="correct"){
                    s=s+t;
                    b++;
                    h=false;
                }
                else{
                    c++;
                }
            }
            else{
                
                if(v=="incorrect"){
                    c++;
                }
                else if(h){
                    
                    s=s+t+(20*c);
                    b++;
                    c=0;
                    h=false;
                }
            }
            
        }
        
        cout<<b<<" "<<s<<"\n";
        s=0;
        c=0;
        b=0;
        h=true;
    }
    
 return 0;   
}