#include<bits/stdc++.h>
using namespace std;
int main(){
    int k=0;
    while(cin>>k && k!=0){
        int x=0, y=0;
        cin>>x>>y;
        while(k--){
            int n=0, m=0;
            cin>>n>>m;

            if(n==x && m==y){
                cout<<"divisa"<<"\n";
            }else if(n>x && m>y){
                cout<<"NE"<<"\n";
            }else if(n>x && m<y){
                cout<<"SE"<<"\n";
            }else if(n<x && m>y){
                cout<<"NO"<<"\n";
            }else if(n<x && m<y){
                cout<<"SO"<<"\n";
            }
        }
    }

 return 0;
}
