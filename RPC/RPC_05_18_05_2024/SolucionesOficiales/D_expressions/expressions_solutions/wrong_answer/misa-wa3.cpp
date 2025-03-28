#include <bits/stdc++.h>

using namespace std;

using ll = long long;

//saving entire products for blocks ... -> OVERFLOW 

int main()
{
	int n, m;
	cin >> n >> m;
	vector<ll> nums(n);
	vector<char> ops(n - 1);
	cin >> nums[0];
	for(int i = 1; i < n; ++i)
	{
		cin >> ops[i - 1] >> nums[i];
	}
	assert(cin.good());
	struct block
	{
		vector<int> elements;
		int parity;
		ll product;
		//int num_even;
	};
	vector<block> blocks;
	vector<pair<int, int>> block_pos(n); //(i,j) -- ith block, index j
	blocks.push_back({{nums[0]}, -1, -1});
	block_pos[0] = {0, 0};
	for(int i = 1; i < n; ++i)
	{
		if(ops[i - 1] == '*')
			blocks.back().elements.push_back(nums[i]);
		else
			blocks.push_back({{nums[i]}, -1, -1});
		block_pos[i] = {blocks.size() - 1, blocks.back().elements.size() - 1};
	}
	
	for(auto& [elements, parity, product]: blocks)
	{
		product = 1;
		for(auto& x: elements)
			product *= x;
		parity = product & 1;
	}
	
	//elements in blocks unused now
	
	int parity_of_odd_blocks = 0;
	for(auto& [_, par, __]: blocks)
		parity_of_odd_blocks += par;
	parity_of_odd_blocks &= 1;
	
	cout << (parity_of_odd_blocks ? "odd" : "even") << '\n';
	
	for(int i = 0; i < m; ++i)
	{
		int x, y;
		cin >> x >> y;
		assert(cin.good());
		--x;
		//update product	
		blocks[block_pos[x].first].product /= nums[x];
		blocks[block_pos[x].first].product *= y;
		if(blocks[block_pos[x].first].parity != (blocks[block_pos[x].first].product & 1))
			parity_of_odd_blocks++;
		blocks[block_pos[x].first].parity = blocks[block_pos[x].first].product & 1;
		parity_of_odd_blocks &= 1;	
		
		nums[x] = y;
		cout << (parity_of_odd_blocks ? "odd" : "even") << '\n';
	}
}
