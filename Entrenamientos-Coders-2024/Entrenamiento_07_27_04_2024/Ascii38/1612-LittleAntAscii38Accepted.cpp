#include<bits/stdc++.h>
using namespace std;
#define llu unsigned long long int
int main(){
	int n;
	scanf("%llu",&n);
	while(n--){
		llu t;
		scanf("%llu",&t);
		if((t & 1) == 0) printf("%llu\n", t >> 1);
		else printf("%llu\n",(t+1) >> 1);
	}
	
	return 0;
}
