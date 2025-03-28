#include<bits/stdc++.h>
using namespace std;
int main(){
   ios_base::sync_with_stdio(0);
   cin.tie(0);
   int n;
   cin >> n;
   while(n--){
       int str = 1;
       //char a[100];
       string a = "";
       //scanf(" %s%*c",a);
       cin >> a;
       transform(a.begin(),a.end(),a.begin(),::tolower);
       for(int i = 0; i < a.size(); i++){
           if(a[i]=='a' || a[i]=='e' || a[i]=='i' || a[i]=='o' || a[i]=='s')
        		str*=3;
           else str*=2;
       }
       cout << str <<"\n";
   }
    return 0;
}
