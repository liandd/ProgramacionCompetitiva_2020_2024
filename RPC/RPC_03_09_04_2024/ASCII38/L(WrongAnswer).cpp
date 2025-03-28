#include<bits/stdc++.h>
using namespace std;

char grid[1000][1000];
char grid2[1000][1000];
int R, C1,C2;
/*
6 6 6
******
******
******
******
******
*****-
--*---
-**---
******
******
-**---
--*---
*/
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	bool flag=false;
	int y=0,y2=0;
	//vector<pair<char,char> > pos;
	cin>>R>>C1>>C2;
	cin.ignore();
	for(int i=0;i<R;i++){
		for(int j=0;j<C1;j++){
			cin>>grid[i][j];	
		}
	}
	for(int i=0;i<R;i++){
		for(int j=0;j<C2;j++){
			cin>>grid2[i][j];
		}
	}
	int cont=0,cont2=1;
	y=R*C1;
	y2=R*C2;
	for(int i=0;i<R;i++){
		for(int k=0;k<C1;k++){
			if(grid[i][k]=='*'){
				cont++;
			}
		}
		cont2++;
		if(cont==y)cont=0;
	
		else if(cont<y && R==cont2){
			for(int k=0;k<C2;k++){
				if(grid2[R-1][k]=='*'){
					cout<<"N\n";
					return 0;
				}
			}
		}
	}
	cout<<"Y\n";
	/*
	if(grid[R-1][5]=='*' && grid2[0][0]=='-' || grid2[0][0]=='*'){
		cout<<"Y\n";
		//grid[R-1][5]=grid2[0][0];
		flag=true;
	}else if(grid[R-1][5]=='-' && grid2[0][0]=='-' || grid2[0][0]=='*'){
		flag=false;
		//break;
		cout<<"N\n";
	}
	/*		
	
	
	//(flag) ? cout<<"Y\n":cout<<"N\n";
	/*
	for(int i=0;i<R;i++){
		for(int j=0;j<C1;j++){
			cout<<grid[i][j];
		}
		cout<<"\n";
	}
	for(int i=0;i<R;i++){
		for(int j=0;j<C2;j++){
			cout<<grid2[i][j];
		}
		cout<<"\n";
	}
	*/
	return 0;
}

