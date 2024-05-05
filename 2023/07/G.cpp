#include<bits/stdc++.h>
using namespace std;
#define fo(i,n) for(int i=0;i<n;i++)
#define ll long long
#define pb push_back
typedef vector<int>		vi;
typedef vector<ll>		vl;
ll gcd(ll a, ll b){if (b == 0)return a;return gcd(b, a % b);}
ll lcm(ll a, ll b){return(a/gcd(a,b))*b;}

ll contMult(ll lim, vl& primes){
  int k=primes.size();
  ll r=0;
  for(int i=1; i<(1<<k);++i){
    int cont = __builtin_popcount(i);
    ll mult=1;
    for(int j=0;j<k;++j){
      if(i&(1<<j)){
        mult=lcm(mult,primes[j]);
      }
    }
    if(cont%2==1)
      r+=lim/mult;
    else
      r-=lim/mult;
  }
  return r; 
}

ll encontrarNth(ll n, vl& primes){
  ll menor=1;
  ll mayor=1e18;
  ll r=-1;

  while(menor<=mayor){
    ll mid=(menor+mayor)/2;
    ll cont= mid-contMult(mid,primes);
    if(cont>=n){
      r=mid;
      mayor=mid-1;
    }else{
      menor=mid+1;
    }
  }
  return r;
}

int main(){

	ios::sync_with_stdio(0);cin.tie(0);
  ll n;
  int k;
  cin>>n>>k;
  vl primes(k);
  fo(i,k) cin>>primes[i];

  ll r=encontrarNth(n,primes); 
  cout<<r<<"\n";
	return 0;
}
