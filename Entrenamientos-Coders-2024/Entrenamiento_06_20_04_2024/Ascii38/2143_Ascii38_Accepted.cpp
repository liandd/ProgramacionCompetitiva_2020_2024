//2143 - The Return of Radar:
#include<bits/stdc++.h>
using namespace std;

int main(){
   int a = 0,b = 0;
   while(cin>>a){
      if(a==0){
         return 0;
      }
      for(int i=0;i<a; i++){
         cin>>b;
	 if(b&1){
            cout<<b*2-1<<"\n";
	 }
	 else cout<<b*2-2<<"\n";
      }
   }
   return 0;
}
