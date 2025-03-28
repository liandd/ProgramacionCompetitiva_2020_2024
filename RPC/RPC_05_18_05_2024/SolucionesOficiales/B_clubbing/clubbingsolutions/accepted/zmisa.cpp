#include <bits/stdc++.h>

using namespace std;

int main()
{
	const int U = 17;
	int n;
	cin >> n;
	vector<string> strs(n);
	for(auto& s: strs)
		cin >> s;
	string s;
	cin >> s;
	
	
	vector<int8_t> msks(1LL << U);
	for(auto& s: strs)
	{
		int m = 0;
		for(auto& c: s)
		{
			m |= (1 << (c - 'a'));
		}
		msks[m] = 1;
	}
	//msks[x] == 1 if substring consisting of x
	
	for(int i = 0; i < (1LL << U); ++i)
	{
		for(int j = 0; j < U; ++j) //j bits
			if(i & (1 << j))
				msks[i] |= msks[i & ~(1 << j)];
	}
	
	
	vector<int> f(U);
	
	int i = 0, j = -1;
	long long total = 0;
	while(true)
	{
		int m = 0;
		for(int i = 0; i < U; ++i)
			if(f[i])
				m |= (1 << i);
		if(msks[m])
		{
			total += s.size() - j;
			++i;
			--f[s[i - 1] - 'a'];
		}
		else
		{
			++j;
			if(j<s.size())
				++f[s[j] - 'a'];
		}
		if(j >= s.size())
			break;
	}
	cout << total << '\n';
}
