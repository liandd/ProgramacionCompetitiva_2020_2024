#include<bits/stdc++.h>
using namespace std;
long long gcd(long long a, long long b){if(b == 0)return a; return gcd(b,a%b);}

long long calcGCD(vector<long long> vi){
	long long r = vi[0];
	for(long long i = 0; i< vi.size(); i++){
		r = gcd(r, vi[i]);
	}
	return r;
}

int main(){
	
	long long  n;
	vector<long long> divisores;
	cin>>n;
	if(n == 1){
		cout<<"N\n";
		return 0;
	}
	for(long long i = 1; i <= sqrt(n); i++){
		if(n % i == 0){	
			if(n/i != i){
			
			divisores.push_back(i);
			divisores.push_back(n/i);
		
			}else{
			divisores.push_back(i);	
			}	
		}
	}

	sort(divisores.rbegin(), divisores.rend());

	vector<long long> a(divisores.size()/2);
	long long cont = 0;
	for(long long i = 0; i < divisores.size();i++){
		if(i%2 == 0){
				a.push_back(divisores[i]);
		}
	}

	long long r = calcGCD(a);
	
	if(r > 1) cout<<"Y\n";
	else cout<<"N\n";
	return 0;
}
