#include<bits/stdc++.h>
using namespace std;
int main(){
    int n=0;
    cin>>n;
    while(n--){
        string str;
        cin>>str;
        
        int c1=0,c2=0,c3=0;
        for(int i=0; i<str.size();i++){
            if(str[i]=='<'){
                c1++;
            }
            if(str[i]=='>' && c1>0){
                c2++;
                c1--;
            }
        }
        
        cout<<c2<<"\n";
    
    }

    return 0;
}