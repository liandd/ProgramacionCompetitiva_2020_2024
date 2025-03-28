#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n, m, c;
	cin >> n >> m >> c;
	int a = 0, b = 0;
	vector<int> sc(m,0);
	for(int i = 0; i < n; ++i)
	{
		int f,s;
		cin >> f >> s;
		if(sc[f] < c)
			sc[f]++,a++;
		else if(sc[s] < c)
			sc[s]++,b++;
	}
	cout << a << ' ' << b << '\n';
}
