#include<bits/stdc++.h>
using namespace std;

int main(){
    
    int h,k,v,s;
    cin>>h>>k>>v>>s;
    int r=0;
    while(h>0){
        v+=s;
        
        v-=max(1,(int)floor(v/10));
        
        
        if(v>=k){
            h=h+1; 
        }else if(0<v && v<k) h--;
        else if(v<=0){
        	h=0;
        	v=0;
		}
        if(h==0) v=0;
        r+=v;        
        if(s>0){
            s=s-1;
        }
    }
    cout<<r<<"\n";
    return 0;
}
