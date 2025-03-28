#include <bits/stdc++.h>

using namespace std;


int main()
{
	int n, m;
	cin >> n >> m;
	vector<int> nums(n);
	vector<char> ops(n - 1);
	cin >> nums[0];
	nums[0] &= 1;
	for(int i = 1; i < n; ++i)
	{
		cin >> ops[i - 1] >> nums[i];
		nums[i] &= 1;
	}
	assert(cin.good());
	struct block
	{
		vector<int> elements;
		int parity;
		int num_even;
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
	
	for(auto& [elements, parity, num_even]: blocks)
	{
		num_even = 0;
		for(auto& x: elements)
			num_even += !(x & 1);
		parity = (num_even == 0); //block is odd iff there is no even number in it
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
		y &= 1;
		if(nums[x] ^ y) //different parity
		{
			if(nums[x] == 1) //odd -> even
				blocks[block_pos[x].first].num_even++;
			else //even -> odd
				blocks[block_pos[x].first].num_even--;
			//check if the parity of the block changed
			if(blocks[block_pos[x].first].parity != (blocks[block_pos[x].first].num_even == 0))
				parity_of_odd_blocks++;
	//		blocks[block_pos[x].first].parity = blocks[block_pos[x].first].num_even == 0; //FORGOT TO UPDATE PARITY OF SEGMENT
			parity_of_odd_blocks &= 1;
		}
		
		nums[x] = y;
		cout << (parity_of_odd_blocks ? "odd" : "even") << '\n';
	}
}
