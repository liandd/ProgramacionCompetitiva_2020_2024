#include <bits/stdc++.h>

using namespace std;

int main() {
	int a,b, c=0, d;

	cin>>a>>b;

	for(int i=0; i<a; i++) {
		cin>>d;
		if(d <= b) {
			c= max(c,d);
		}

	}

	cout<<d<<"\n";

	return 0;
}