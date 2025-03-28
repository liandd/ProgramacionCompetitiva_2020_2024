#include<bits/stdc++.h>
using namespace std;
int main(){
    int n=0, r=0;
    cin>>n>>r;

    int h=pow(2,n);
    //cout<<h;
    int c=0;
    int w=h/2;
    for(int i=w; i>=2; i=i/2){
        if(r<h){
            c++;
        }
    }
    if(r==2){
        c++;
    }
    cout<<max(1,c)<<"\n";
    return 0;
}
