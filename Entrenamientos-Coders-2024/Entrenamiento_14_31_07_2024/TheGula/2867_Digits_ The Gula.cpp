#include <bits/stdc++.h>

using namespace std;

void no(){
		int v,a,b;
		long long c;
		scanf("%d%d",&a,&b);
		c=pow(a,b);
		c=to_string(c).size();
		printf("%d\n", c);
} 

int main() {

	int v,a,b;
	scanf("%d", &v);
	while(v--) {
		long long c;
		scanf("%d%d", &a,&b);
		c=floor(b * log10(a)) + 1;
		printf("%d\n", c);
	}


	return 0;
}