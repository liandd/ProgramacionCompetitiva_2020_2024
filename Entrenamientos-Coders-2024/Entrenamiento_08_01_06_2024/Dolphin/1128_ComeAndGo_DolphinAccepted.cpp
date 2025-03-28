#include<bits/stdc++.h>
using namespace std;
# define INF -1
typedef vector <int> vi;
vector <vi> adjList;
vi dist;
vi dfs_num;
int source,n,e,cont;

void DFS (int u){
	dfs_num[u]=1;
	for(int j = 0; j <adjList[u].size();j++){
		int v = adjList[u][j];
		if(dfs_num[v]== INF)DFS(v);
	}
}

void BFS(){
	dist[source]=0;
	queue <int> q;
	q.push(source);
	while(!q.empty()){
		int u= q.front();
		q.pop();
		for(int i= 0;i< (int)adjList[u].size();i++){
			if(dist[i]!=INF)continue;
			dist[i] = dist[u]+1;
			q.push(i);

		}

	}
}

int main(){

	while(cin>>n>>e&&n!= 0&&e!=0){

	cont=0;
	adjList.assign(n,vi(0));
	dfs_num.assign(n, INF);
	source=0;

	while(e--){

		int a,b,p;

		cin>>a>>b>>p;
		a--;
		b--;
		adjList[a].push_back(b);
		if(p==2){
		adjList[b].push_back(a);

		}
	}


	for(int j= 0;j< n;j++){
		DFS(j);
		//cont = 0;
		for(int i =0;i<dfs_num.size();i++){
			if (dfs_num[i]!=INF){
				cont++;
			}
		}
		dfs_num.assign(n, INF);
	}
	if(cont==n*n){
		cout<<"1"<<"\n";
	}else{
		cout<<"0"<<"\n";
	}

}

return 0;
}
