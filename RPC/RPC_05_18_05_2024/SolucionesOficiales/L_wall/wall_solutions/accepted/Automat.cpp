#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<int> rules;


int computeNextGen(int l, int c, int r)
{
		return rules[4*l + 2*c + r];
}


int main()
{
	int R, k;
	string start;
	
	cin >> R >> k;
	cin >> start;
	
	vector<int> v;
	for(int i = 0;i<start.length();i++)
	{
		if(start[i] == 'X')
			v.push_back(1);
		else if (start[i] == '.')
			v.push_back(0);
		else return 1;	
	}	

	int tmp = R;
	for(int i = 0;i<8;i++)
	{
		if(tmp & 1)
			rules.push_back(1);
		else
			rules.push_back(0);
			
		tmp = tmp >> 1; //divides tmp by 2
	}
		
	
	for(int step = 0;step<k;step++)
	{	
		vector<int> nextGen; 
		nextGen = v;
			
						
		nextGen[0] = computeNextGen(0,v[0],  v.size() > 1 ? v[1] : 0);
	
		for(int i = 1;i<v.size()-1;i++)
		{
			nextGen[i] = computeNextGen(v[i-1], v[i], v[i+1]);		
		}			
		
		nextGen[nextGen.size()-1] = computeNextGen(v.size() > 1 ? v[v.size()-2] : 0,v[v.size()-1],0);

		
		
		v = nextGen;	
		
	for(int i = 0;i<v.size();i++)
		cout << (v[i]? 'X' : '.');
		
	cout << endl;
			
	}
	
	

	return 0;
}
