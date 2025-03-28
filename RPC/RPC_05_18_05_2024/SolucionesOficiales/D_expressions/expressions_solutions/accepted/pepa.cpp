#include <bits/stdc++.h>

using namespace std;


int main()
{
	int n, m;
	cin >> n >> m;
	
	int oddBlocks = 0;
	vector<int> blocks = {0};
	vector<pair<int,int>> pointers;
	
	int currBlock = 0;
	for(int i = 0;i<n;i++)
	{	
		int num;
		cin >> num;
		
	
		pointers.push_back({num,currBlock});
		
		if(num % 2 == 0)
		{	
			blocks[currBlock]++; 
		}
			
			
		if(i == n-1) break;
		
		char c;
		cin >> c;
		
		if(c == '+' || c == '-') {currBlock++;blocks.push_back(0);};				
	}
	
	for(int i = 0;i<(int)blocks.size();i++)
	{
		if(blocks[i] == 0) oddBlocks++;
	}
	
	cout << (oddBlocks % 2 == 0 ? "even" : "odd") << endl;
	
	
	for(int i = 0;i<m;i++)
	{
		int pos, neu;
		cin >> pos >> neu;
		pos--;
		
		if(pointers[pos].first %2 != neu%2)
		{
		
			pointers[pos].first = neu;

			if(neu % 2 == 0)
			{
				if(blocks[pointers[pos].second]== 0)
					oddBlocks--; 
				blocks[pointers[pos].second]++;
			
			}
			else
			{
				blocks[pointers[pos].second]--;
				if(blocks[pointers[pos].second]== 0)
					oddBlocks++;			
			}
		}
		
		cout << (oddBlocks % 2 == 0 ? "even" : "odd") << endl;
		
	}
	
	return 0;
}
