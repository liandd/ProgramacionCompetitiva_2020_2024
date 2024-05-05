#include <bits/stdc++.h>

using namespace std;

int main(){
    string s, t;
    cin>>s>>t;
    int suma=0, antpos=-1,anti=-1, control=0;
    for (int i=0; i<s.size()-t.size(); i++){
        int der=1, pos=0;
        if (s[i]==t[0]){
            if(t.size()>1){
                for (int j=i+1; j<s.size() && der<t.size(); j++){
                    if (s[j]==t[der]){
                        der++;
                        pos=j;
                    }
        
                }
                if (der==t.size()){
                    if (control==0){
                        suma+=i;
                        suma+=(s.size()-pos-1);
                        suma+=(i*(s.size()-pos-1))+1;
                        antpos=pos;
                        anti=i;
                        control++;
                    }else if(antpos!=pos){
                        suma+=(i-anti-1);
                        suma+=(s.size()-pos-1);
                        suma+=(i*(s.size()-pos-1))+1;
                        antpos=pos;
                        anti=i;
                    }else if(antpos==pos){
                        suma+=(i-anti-1);
                        suma+=((i-anti-1)*(s.size()-pos-1))+1;
                    }
                }
            }else{
                suma+=i;
                suma+=(s.size()-i-1);
                suma+=(i*(s.size()-i-1))+1;
            }
            
            
        }
    }
    cout<<suma<<"\n";
    
    
    
    
    return 0;
}