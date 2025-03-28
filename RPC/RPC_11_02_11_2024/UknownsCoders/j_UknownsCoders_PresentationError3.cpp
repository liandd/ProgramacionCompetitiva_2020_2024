#include<iostream>
#include<string>
#include<vector>
#include<utility>
#include<algorithm>
using namespace std;
int main(){

long long n=0,m=0,n2=0,k=0,np=0;
long long k2=LONG_MAX;
vector<long long> vec;

cin>>n;
cin>>m;

for(int i=0;i<n;i=i+1){
    cin>>n2;
    vec.push_back(n2);
}

if(n<=m){
 k2=0;
 for(int i=0;i<n;i=i+1){
    np=vec[i];
    if(np>k2){
        k2=np;
    }
 }
}else{
    for(int i=0;i<n;i=i+1){
        for(int j=0;j<n;j=j+1){
            k=vec.at(i)+vec.at(j);
            if(k<k2&&i!=j){
                k2=k;
            }
        }
    }
}

cout<<k2;



    return 0;
}
