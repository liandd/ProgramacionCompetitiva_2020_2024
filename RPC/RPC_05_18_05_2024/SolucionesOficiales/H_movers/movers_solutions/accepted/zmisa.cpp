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
	
	int SQRTM = sqrt(m);
	auto is_small = [&](int v) { return dg[v] <= SQRTM; };
	
	for(auto& a: adj)
		std::partition(a.begin(), a.end(), not_fn(is_small));
	
	vector<int> ds(n), gs(n); //ds[n] -- sum of small neighbors
	
	for(int v = 0; v < n; ++v)
		for(auto& u: adj[v])
		{
			if(is_small(u))
			{
				ds[v] += d[u];
				gs[v] += g[u];
			}
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
			auto& s = (who == "desk" ? d : g);
			auto& ss = (who == "desk" ? ds : gs);
			
			//add to self
			s[v] += k;
			
			//if im small, increment all my neighbors total value
			if(is_small(v))
			{
				for(auto& u: adj[v])
				{
					ss[u] += k;
				}
			}
		}
		else
		{
			int v;
			cin >> v;
			--v;
			
			int dres;
			int gres;
			if(is_small(v))
			{
				dres = d[v];
				gres = g[v];
				for(auto& u: adj[v])
				{
					dres += d[u];
					gres += g[u];
				}
			}
			else
			{
				dres = ds[v] + d[v];
				gres = gs[v] + g[v];
				for(auto& u: adj[v])
				{
					if(is_small(u))
						break;
					dres += d[u];
					gres += g[u];
				}
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
