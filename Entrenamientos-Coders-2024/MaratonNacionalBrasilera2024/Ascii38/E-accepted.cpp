#include<bits/stdc++.h>
using namespace std;

int main(){
	int n=0;
	cin>>n;
	int grid[n][n];
	int tmp=-1;
	vector<int> menor;
	vector<int> actual;
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			cin>>grid[i][j];
			actual.push_back(grid[i][j]);
		}
		sort(actual.begin(),actual.end());
		menor.push_back(actual[0]);
	}
	/*for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			cout<<grid[i][j]<<" ";
		}
		cout<<"\n";
	}	*/
	sort(menor.begin(), menor.end());
	tmp=menor[0];
	if(grid[0][0]==tmp){
		cout<<"0\n";
	}
	else{
		if(grid[0][n-1]==tmp){
			cout<<"1\n";
		}
		else if(grid[n-1][n-1]==tmp){
			cout<<"2\n";
		}
		else if(grid[n-1][0]==tmp){
			cout<<"3\n";
		}
	}
	return 0;
}
