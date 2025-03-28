#include<bits/stdc++.h>
using namespace std;
int R,C,K;

char grid[1000][1000];
char grid2[1000][1000];
bool ls( int r, int c, int k){
	for(int t=0;t+K<=c;t++){
		bool flag=true;
		for(int i=0;i<r;i++){
			for(int j=0;j<k;j++){
				if(grid2[i][j]=='*' && grid[i][t+i]=='-'){
					flag=false;
					break;
				}
				if(grid2[i][j]=='-' && grid[i][t+i]=='-'){
					flag=false;
					break;
				}
			}
			if(!flag)break;
		}
		if(flag){
			return true;
		}
	}
	return false;
}
int main(){
	cin>>R>>C>>K;
	cin.ignore();
	for(int i=0;i<R;i++){
		for(int j=0;j<C;j++){
			cin>>grid[i][j];	
		}
	}
	for(int i=0;i<R;i++){
		for(int j=0;j<K;j++){
			cin>>grid2[i][j];	
		}
	}
	if(ls(R,C,K)){
		cout<<"Y\n";
		return 0;
	}
	else cout<<"N\n";
	return 0;
}
