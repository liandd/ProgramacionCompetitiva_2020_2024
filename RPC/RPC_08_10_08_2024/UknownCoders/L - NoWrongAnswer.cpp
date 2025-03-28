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

    if(c1>2){
        c1=2;
    }
    int h=0;
    for(int i=32; i<=524290; i=i*2){
        if(c+c1>h /*&& c+c1<=i*/){
            cout<<"long";
        }
        if(c+c1>i){
            cout<<" ";
        }
        h=i;
        //cout<<h;
    }
    cout<<"\n";
    return 0;
}
