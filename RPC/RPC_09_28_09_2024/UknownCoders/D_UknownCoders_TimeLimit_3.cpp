#include<bits/stdc++.h>
using namespace std;
int main(){
    long long n,m,high,j,k=1;
    cin>>n>>m;//7 2
    vector<long long> vec;
    vector<long long> high2;
    for(int i=0;i<n;i=i+1){
       cin>>high;
       vec.push_back(high);
    }

    if(n<3){
      cout<<vec.at(1)-vec.at(0);
    }else if(n==1){
      cout<<vec.at(0);
    }else {
        if(m>n){
            m=n;
        }
    for(int i=0;i<n-1;i=i+1){
        long long k3=(n-i);
        if(k3<m){
          m=k3;
        }
        long long high4=*max_element(vec.begin()+(i+1),vec.begin()+(m+i));
        long long np=*min_element(vec.begin()+(i+1),vec.begin()+(m+i));
       // cout<<high4<<"high"<<"\n";
        //cout<<np<<"np"<<"\n";
        if(high4>vec.at(i)){
            long long score=high4-vec.at(i);
            high2.push_back(score);
          //   cout<<score<<"\n";
        }else {
            long long score2=np-vec.at(i);
            high2.push_back(score2);
            // cout<<score2<<"\n";
        }

    }


    long long high3=*max_element(high2.begin(),high2.end());
    //long long prueba=*max_element(vec.begin(),vec.begin()+2);

    cout<<high3;
    }
    return 0;
}
