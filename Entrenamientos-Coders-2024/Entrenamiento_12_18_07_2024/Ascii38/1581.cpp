#include <bits/stdc++.h>
using namespace std;

int main() {

    int n=0;
    cin>>n;
    while(n--){
     int k=0;
    string str="";
    set<string>idiomas;
    cin>>k;
    for(int i=0; i<k; i++){
       cin>>str;
       idiomas.insert(str);

    }//for

      if(idiomas.size()>1){
     cout<<"ingles\n";
      } else{
         cout<<str<<"\n";
      }

    }//while

	return 0;
}
