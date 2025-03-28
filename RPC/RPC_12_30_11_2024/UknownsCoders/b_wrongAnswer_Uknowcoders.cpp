#include<bits/stdc++.h>
using namespace std;
int main(){

 long long l=0,w=0,h=0,n=0,m=0,m2=0;

vector<long long> l2;
vector<long long> w2;
vector<long long> h2;

cin>>n>>m;//3


for(long long i=0;i<n;i=i+1){
     cin>>l>>w>>h;
     l2.push_back(l);//10
     w2.push_back(w);//2
     h2.push_back(h);//5
}

for( long long i=0;i<n;i=i+1){


    if(h2.at(i)<=m){
        m2=m2+min(w2.at(i),l2.at(i));
    }else if(w2.at(i)<=m){
        m2=m2+min(l2.at(i),h2.at(i));
    }else if(l2.at(i)<=m){
      m2=m2+l2.at(i);
    }

}

  if(m2==0){
    cout<<"impossible"<<"\n";
  }else{
  cout<<m2<<"\n";
  }





return 0;
}
