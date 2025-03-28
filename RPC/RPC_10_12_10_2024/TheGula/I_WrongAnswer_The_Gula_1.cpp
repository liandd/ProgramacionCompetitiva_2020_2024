#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int a, b;
	cin>>a;
	cin>>b;

	vector<pair<int, bool>> hab;

	for(int i=0; i<=a ; i++) {
		hab.push_back(make_pair(i,false));
	}

	char let;
	for(int i=0; i<8 ; i++) {
		cin>>let;
		if(let=='A') {
			long long ini, fin;
			cin>>ini>>fin;
			int cont=0;
			for(int j=ini; j<=fin; j++) {
				if(hab[j].second==false) {
					cont++;
				}
			}
			cout<<cont<<"\n";
		} else if(let=='R') {
			long long habbb;
			cin>>habbb;
			hab[habbb]=make_pair(habbb,true);
		}
	}
	return 0;
}