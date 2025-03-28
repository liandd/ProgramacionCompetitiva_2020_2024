#include <bits/stdc++.h>

using namespace std;

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	set<long long> nums;
	string pal;
	cin>>pal;

	for(int i=0; i<pal.size(); i++) {
			nums.insert((int)pal[i]);		
	}

	cout<<nums.size()-1<<"\n";

	return 0;
}