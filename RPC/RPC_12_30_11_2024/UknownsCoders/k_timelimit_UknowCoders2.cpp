#include<bits/stdc++.h>
using namespace std;
int main(){
string s="",t="",s2="";
cin>>s>>t;


for(int i=0;i<t.size();i=i+1){
    if(i!=0){
      s=s2;

    }
    switch(t.at(i)){
    case 'h':
        s2="";
     for(int j=0;j<s.size();j=j+1){

        if(s.at((s.size()-1)-j)=='b'){
            s2=s2+'d';

        }else if(s.at((s.size()-1)-j)=='d'){
          s2=s2+'b';

        }else if(s.at((s.size()-1)-j)=='p'){
         s2=s2+'q';

        }else{
         s2=s2+'p';

        }

     }
     break;
    case 'v':
        s2="";
        for(int w=0;w<s.size();w=w+1){
           if(s.at(w)=='b'){
            s2=s2+'p';
           }else if(s.at(w)=='d'){
           s2=s2+'q';
           }else if(s.at(w)=='p'){
           s2=s2+'b';
           }else{
           s2=s2+'d';
           }
        }
        break;

    case'r':

        s2="";
        for(int l=0;l<s.size();l=l+1){

           if(s.at((s.size()-1)-l)=='b'){
            s2=s2+'q';

        }else if(s.at((s.size()-1)-l)=='d'){
          s2=s2+'p';

        }else if(s.at((s.size()-1)-l)=='p'){
         s2=s2+'d';
        }else{
         s2=s2+'b';
        }
        }
        break;
      }
}
 cout<<s2<<"\n";




return 0;
}
