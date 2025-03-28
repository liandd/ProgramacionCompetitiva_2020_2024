#include<bits/stdc++.h>
using namespace std;
int main(){
 int num=0,num2=0;
 bool flag=true;
 string word="",word2="";
 vector<string> vec;
 vector<string> vec2;

 cin>>num;

 for(int i=0;i<num;i=i+1){
    cin>>word;
    vec.push_back(word);
 }

 for(int j=0;j<num;j=j+1){
    cin>>word;
    vec2.push_back(word);
 }

 for(int i=0;i<num;i=i+1){
    for(int j=0;j<num;j=j+1){
        if(vec.at(i)==vec2.at(j)){
        if(flag){
            flag=false;
            num2=(i-j);
            word2=vec.at(i);
        }
        if((i-j>num2)){
            num2=(i-j);
            word2=vec.at(i);
          }



        }
    }
 }

 if(num2!=0){
 cout<<word2<<"\n";
 }else{
cout<<"suspicious"<<"\n";
 }

return 0;
}
