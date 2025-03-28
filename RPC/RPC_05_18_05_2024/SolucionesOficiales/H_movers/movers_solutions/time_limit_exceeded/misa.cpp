#include <bits/stdc++.h>

using namespace std;

int main()
{
	int n, m, q;
	cin >> n >> m >> q;
	vector<int> d(n), g(n);
	vector<vector<int>> adj(n);
	vector<int> dg(n);
	for(auto& x: d) cin >> x;
	for(auto& x: g) cin >> x;
	for(int i = 0; i < m; ++i)
	{
		int u, v;
		cin >> u >> v;
		--v, --u;
		adj[u].push_back(v);
		adj[v].push_back(u);
		++dg[u];
		++dg[v];
	}
	
	while(q--)
	{
		string what;
		cin >> what;
		
		if(what == "add")
		{
			string who;
			int v;
			int k;
			cin >> k >> who >> v;
			--v;
			(who == "desk" ? d : g)[v] += k;
		}
		else
		{
			int v;
			cin >> v;
			--v;
			
			int dres = d[v];
			int gres = g[v];
			for(auto& u : adj[v])
			{
				dres += d[u];
				gres += g[u];
			}
			
			if(dres > gres)
				cout << "desks\n";
			else if(dres < gres)
				cout << "monitors\n";
			else
				cout << "same\n";
		}
	}
}
