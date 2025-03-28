#include <bits/stdc++.h>

using namespace std;

using ll = long long int;
using ld = long double;
using vll = vector<ll>;

#define fr(i, x) for(ll i = 0; i < (x); ++i)

void solve(){
	ll n;
	cin >> n;
	if(n %2 == 0){
		cout << 2 << " " << n/2 << endl;
		return;
	}
	for(int i = 3;; i+=2){
		if(n%i == 0){
			cout << i << " " << n/i << endl;
			return;
		}
	}
}

int main(void){
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin.exceptions(cin.failbit);
	cout<<setprecision(9)<<fixed;
	ll t = 1;
	// cin >> t;
	fr(i, t){
		solve();
	}
	return 0;	
}
