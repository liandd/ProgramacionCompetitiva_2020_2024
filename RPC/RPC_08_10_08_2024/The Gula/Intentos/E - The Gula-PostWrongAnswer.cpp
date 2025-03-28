#include <bits/stdc++.h>

using namespace std;

int main() {
	int n;
	cin>>n;

	vector<pair<int, int>> puntos(n);

	for (int i = 0; i < n; ++i) {
		cin>>puntos[i].first>>puntos[i].second;
	}

	long long vol = 0;

	for (auto punto : puntos) {
		long long vol2 = punto.first * punto.second * min(punto.first, punto.second);
		vol = max(vol, vol2);
	}


	cout<<vol<<"\n";
	return 0;
}