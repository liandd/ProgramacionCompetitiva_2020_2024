#include <bits/stdc++.h>

using namespace std;

int main() {
	long long n, m, a,b;

	scanf("%lld %lld", &n, &m);

	set<pair<long long, int >> num;
	
	for(int i=0 ; i<m ; i++) {
		scanf("%lld %d", &a, &b);
		if(b!=3){
		num.insert(make_pair(a,b));	
		}
	}
	
	set<long long> res;
	int aux=0;
	long long axnum=0;
	for(auto i: num){	
		if(i.second==1){
			aux=1;
			axnum=i.first;
		}else if(i.second==2 && aux==1 && axnum==i.first){
			res.insert(i.first);
			aux=0;
		}
	}
	
	//for(auto i: num ) {
	//	cout<<i.first<<"   "<<i.second<<"\n";
	//}
	
	for(auto i: res ) {
		cout<<i<<"\n";
	}

	return 0;
}