#include <bits/stdc++.h>
using namespace std;

int main() {
	int n; cin >> n;
	map<string, map<string, int>> medias;
	while (n--) {
		string tipo, talla;
		cin >> tipo >> talla;
		int cnt; cin >> cnt;
		medias[tipo][talla] += cnt;
	}

	bool possible = false;
	int res = 1;
	for (auto [tipo, cnts]: medias) {
		int left = cnts["left"], right = cnts["right"], any = cnts["any"];
		if (left+any >= 1 && right+any >= 1 && left+right+any >= 2) possible = true;
		res += max(left,right) + (left+right == 0);
	}
	
	if (possible) cout << res << endl;
	else cout << "impossible" << endl;
}
