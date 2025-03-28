#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define vi vector<int>
#define vll vector<ll>
#define pb push_back

vi primeFactors(ll N, vi &primes){
	vi factors;
	ll PF_idx = 0, PF = primes[PF_idx];
	while(PF*PF<=N){
		while(N%PF == 0){
			N/=PF;
			factors.pb(PF);
		}
		PF=primes[++PF_idx];
	}
	if(N != 1) factors.pb(N);
	return factors;
}

int main(){
	ll C;
	int M;
	cin >>C>>M;
	vi primes (M);
	for(int i = 0; i<M; ++i){
		cin>>primes[i];
	}
	sort(primes.begin(), primes.end());
	vi sorner = primeFactors(C, primes);
	for(int i = 0; i < sorner.size(); i++){
		if(sorner[i]!=sorner[(i+1)%sorner.size()])
			cout<< sorner[i]<< " ";
			else{
				cout<<"No answer\n";
				return 0;
			} 
	}
	cout<<"\n";
	return 0;
}

