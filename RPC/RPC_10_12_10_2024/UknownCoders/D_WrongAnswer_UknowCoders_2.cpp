#include<bits/stdc++.h>
using namespace std;

int main(){

 int n=0, r=0, cont=0, ne=0,rd=0;
 cin>>n>>r;
 ne=pow(2,n);
 rd =ne/2;
 for(int i=rd; i>=2; i=i/2){
       if(r<ne){
       cont++;
      }
    }
    if(r==2 && n>2){
        cont++;
 }

  cout<<max(1,cont)<<"\n";
 return 0;
}
