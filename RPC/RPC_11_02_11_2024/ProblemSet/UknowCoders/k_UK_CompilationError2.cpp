#include<iostream>
#include<string>
#include<vector>
#include<utility>
#include<algorithm>
using namespace std;
int main(){

long long n,m,n2,k,k2=LONG_MAX;
vector<long long> vec;

cin>>n;
cin>>m;

for(int i=0;i<n;i=i+1){
    cin>>n2;
    vec.push_back(n2);
}

if(n<=m){
 k2=*max_element(vec.begin(),vec.end());
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
