#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
typedef vector<ll> vll;
typedef pair<ll, ll> pl;

ll _sieve_size;
bitset<10000010> bs;
vll p;

void sieve(ll upperbound){
	_sieve_size = upperbound + 1;
	bs.set();
	bs[0] = bs[1] = 0;
	for(ll i = 2; i < _sieve_size; i++){
		if(bs[i]){
			for(ll j = i * i; j < _sieve_size; j += i){
				bs[j] = 0;
			}
			p.pb(i);
		}
	}
}

int main(){
	sieve(10000000);
	ll n = 0;
	scanf("%lld", &n);
	if(n == 1){
		printf("N\n");
		return 0;
	}
	vector<pl> factores;
	for(ll i: p){
		if(i * i > n) break;
		if(n % i == 0){
			int potencias = 0;    
			while(n % i == 0){
				n /= i;
				potencias++;
			}
			factores.pb({i,potencias});
		}
	}
	if(n > 1) factores.pb({n, 1});
	if((factores.size() == 1 && factores[0].second % 2 != 0) ||  (factores.size() == 2 && (factores[0].second == 1 && factores[1].second == 1))){
		printf("Y\n");
	}
	else printf("N\n");
	return 0;
}

