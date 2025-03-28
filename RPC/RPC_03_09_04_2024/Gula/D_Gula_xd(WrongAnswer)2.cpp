#include <bits/stdc++.h>
using namespace std;

long long kl(long long a, long long b){
    while(b !=0){
      long long tem =b;
       b= a%b;
       a=tem;
   }
   return a;
}

vector<long long> multi(int x){
    vector<long long> d;
    int i;
    if(x %2 ==0){
        i=2;
    }else{
        i=1;
    }
    for(i; i<=sqrt(x); ++i){
        if(x %i == 0){
            d.push_back(i);
        }
        /*if(x/i != i){
            d.push_back(x/i);
        }*/
    }
    return d;
}


int main (){
  int x;

  cin >> x;

    
    vector <long long> jj= multi(x);
    
    long long mcd =jj[0];
    
    for(auto i=1; i<jj.size(); ++i){
        mcd=kl(mcd, jj[i]);
    }
    
    if(mcd != 1){
        cout<<"Y\n";
    }else{
        cout<<"N\n";
    }
  return 0;
}

