#include <bits/stdc++.h>
using namespace std;

string step(const string& s, int r)
{
	auto n = s.size();
	string new_s(n,'a');
	for(int i = 0; i < n; ++i)
	{
		int pat = 0;
		if(i > 0 && s[i-1] == 'X')
			pat |= (1<<2);
		if(i < n - 1 && s[i+1] == 'X')
			pat |= (1<<0);
		if(s[i] == 'X')
			pat |= (1<<1);
		if(r&(1<<pat))
			new_s[i]='X';
		else
			new_s[i]='.';
	}
	return new_s;
	
}
int main()
{
	int r, k;
	string s;
	cin >> r >> k;
	cin >> s;
	while(k--)
	{
		s=step(s,r);
		cout << s << '\n';
	}
	return 0;
}
