#include<bits/stdc++.h>
using namespace std;

int main(){
ios_base::sync_with_stdio(0);
cin.tie(0);
string str1, str3;
cin>>str1>>str3;

//sort(str3.begin(), str3.end());
int h=0, v=0, r=0;
for(int i=0; i<str3.size(); i++){
    if(str3[i]=='h'){
        h++;
    }else if(str3[i]=='v'){
        v++;
    }else{
        r++;
    }
}

while(h!=0 && v!=0 && r!=0){
    h--;
    v--;
    r--;
}
string str2;
for(int i=0; i<h; i++){
    str2+='h';
}
for(int i=0; i<v; i++){
    str2+='v';
}
for(int i=0; i<r; i++){
    str2+='r';
}



for(int i=0; i<str2.size(); i++){

switch(str2[i]){

case 'h':{


for(int j=0; j<str1.size(); j++){
 if(str1[j]=='b'){
  str1[j]='d';

 } else if(str1[j]=='d'){
  str1[j]='b';

 } else if(str1[j]=='q'){
  str1[j]='p';

 }else if(str1[j]=='p'){
  str1[j]='q';
  }



}//for

reverse(str1.begin(), str1.end());


break;
}//case h

case 'v':{


for(int j=0; j<str1.size(); j++){
 if(str1[j]=='b'){
  str1[j]='p';

 } else if(str1[j]=='d'){
  str1[j]='q';

 } else if(str1[j]=='q'){
  str1[j]='d';

 }else if(str1[j]=='p'){
  str1[j]='b';
  }



}//for

break;
}//case v


case 'r':{


for(int j=0; j<str1.size(); j++){
 if(str1[j]=='b'){
  str1[j]='q';

 } else if(str1[j]=='d'){
  str1[j]='p';

 } else if(str1[j]=='q'){
  str1[j]='b';

 }else if(str1[j]=='p'){
  str1[j]='d';
  }

}//for

reverse(str1.begin(), str1.end());


break;
}//case r



}//switch

}//for main



cout<<str1<<"\n";



return 0;
}
