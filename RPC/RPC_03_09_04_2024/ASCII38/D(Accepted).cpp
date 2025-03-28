#include<bits/stdc++.h>
using namespace std;

#define fo(i,n) for(auto i=0;i<n;i++)
#define ll long long
#define si(x)	scanf("%d",&x)
#define sl(x)	scanf("%lld",&x)
#define ss(s)	scanf("%s",s)
#define pi(x)	printf("%d\n",x)
#define pl(x)	printf("%lld\n",x)
#define ps(s)	printf("%s\n",s)
#define pb push_back
#define F first
#define S second
typedef vector<ll>		vl;
typedef pair<ll, ll>	pl;

ll _sieve_size;
bitset<10000010> bs;
vl p;

void sieve(ll upperbound){
    _sieve_size = upperbound+1;
    bs.set();
    bs[0] = bs[1] = 0;
    for(ll i = 2; i < _sieve_size; ++i) if(bs[i]){
        for(ll j = i*i; j < _sieve_size; j += i)bs[j] = 0;
        p.pb(i);
    }
}

int main(){
    sieve(10000000);
    ll n;
    sl(n);

    if(n == 1){
        cout<<"N\n";
        return 0;
    }
    vector<pl> factors;
    for(ll i: p){
        if(i * i > n) break;
        if(n % i == 0){
            int power = 0;
            while(n % i == 0){
                n /= i;
                power++;
            }
            factors.pb({i,power});
        }
    }
    if(n > 1) factors.push_back({n, 1});
    
    if((factors.size() == 1 && factors[0].S % 2 != 0) || (factors.size()==2&&(factors[0].S == 1 && factors[1].S == 1))){
        cout<<"Y\n";
    }else{
        cout<<"N\n";
    }
    return 0;
}
