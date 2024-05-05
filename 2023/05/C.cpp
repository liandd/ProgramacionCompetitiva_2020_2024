#include<bits/stdc++.h>
using namespace std;

int main(){

   ios::sync_with_stdio(0);cin.tie(0);
   int n=0,c=0,r=0;
   cin>>n;
   char s[n+1];
   for(int i=0;i<n;++i){
    cin>>s[i];
    if(s[i]=='1')c=3;
    if(c>0)r++;
    c--;
   }
   cout<<r<<"\n";

    return 0;
}
