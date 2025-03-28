#include <bits/stdc++.h>


using namespace std;
int main() {
	int n;
	long long a,b, x=0;
	cin>>n;

	while(n--) {

		cin>>a>>b;

		if(a%2==0 && b%2==0) {

			x=(a*b)/9;
			cout<<floor(x)<<"\n";
		} else if(a > b || a < b) {

			x=((a)*(b))/9;			
			cout<<floor(x-1)<<"\n";
		} else {

			x=((a-1)*(b-1))/9;
			cout<<floor(x)<<"\n";
		}
	}










	return 0;
}