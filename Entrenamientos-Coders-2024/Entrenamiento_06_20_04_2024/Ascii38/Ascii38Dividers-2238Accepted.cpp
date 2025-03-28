#include<bits/stdc++.h>
using namespace std;
#define ll long long

vector<ll> divisoresC(int n){
    vector<ll> d;
    for(int i = 1; i<=sqrt(n); ++i){
        if(n%i == 0){
            d.push_back(i);

            if(i != n/i ){
                d.push_back(n/i);
            }
        }
    }
    sort(d.begin(), d.end());
    return d;
}

int main(){
    ll a,b,c,d;
    cin>>a>>b>>c>>d;
    vector<ll>  n = divisoresC(c);  
    for(int i = 0; i < n.size(); ++i){
        if(n[i] >= a && n[i]%a == 0 && n[i]%b != 0 && d%n[i]!=0){
            cout<< n[i] << "\n";
            return 0;
        }
    }
        
    
    cout<< -1 <<"\n";
    return 0;
}
