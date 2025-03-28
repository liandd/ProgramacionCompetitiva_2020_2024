#include<bits/stdc++.h>
using namespace std;
int main(){
    string str;
    cin>>str;
    int c1=0, c=0;
    for(int i=0; i<str.size(); i++){
        if(str[i]==49){
            c1++;
        }else{
            c++;
        }
    }

   
    for(int i=32; i<=524290; i=i*2){
        if(c+c1>i /*&& c+c1<=i*/){
            cout<<"long ";
        }
        
     
        //cout<<h;
    }
    
    cout<<"long\n";
    return 0;
}
