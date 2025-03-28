#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main()
{
	ll c;
	cin >> c;
	int m;
	cin >> m;
	while(m--)
	{
		ll x;
		cin >> x;
		if(c % x == 0)
		{
			cout << min(x,c/x) << ' ' << max(x,c/x) << '\n';
			return 0;
		}
	}
}
