#include<bits/stdc++.h>
using namespace std;
#define lli long long int

vector<lli>divisoresC(int n, int t){
	vector<lli> d;
	for(int i=1; i<=sqrt(t);i++){
		if(t%i==0 && n>=i){
			d.push_back(i);
			if(i!=t/i && n>=(t/i)){
				d.push_back(t/i);
			}
		}
	}
	sort(d.begin(),d.end());
	return d;
}

int main(){
	int q, n, t;
	scanf("%d", &q);
	
	while(q--){
		vector<lli> res;
		scanf("%d %d", &n, &t);
		t--;
		res = divisoresC(n,t);
		(res.size()==0)? printf("%d\n",n) : printf("%lld\n", res.size());
	}
	
	return 0;
}
