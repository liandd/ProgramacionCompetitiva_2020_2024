#include <bits/stdc++.h>
using namespace std;

bool solve() {
	int alto, ancho;
	cin >> alto >> ancho;

	int ans = ancho;
	while (alto--) {
		int inferior; cin >> inferior;
		if (inferior > ans) return false;
		if ((ans-inferior)%2 == 0) {
			ans = min(ans+1, ancho);
		} else {
			ans = ans-1;
		}
	}
	return ans == ancho;
}
int main() {
	cout << (solve() ? "possible" : "impossible") << '\n';
}
