#include <bits/stdc++.h>
using namespace std;

#define INF -1

typedef vector<int> vi; 
typedef vector<vector<int>> vii;
vii adjList;  
vi dfs_num; 
int source, n, e;

void DFS(int u) {
    dfs_num[u] = 1; 
    for (int j = 0; j < adjList[u].size(); j++) {
        int v = adjList[u][j];
        if (dfs_num[v] == INF)
            DFS(v);
    }
}

int main() {
    cin >> n >> e; 

    adjList.assign(n + 1, vi());  

    source = 1; 
    int cont =0;
    while (e--) {
        int a, b;
        cin >> a >> b;
        adjList[a].push_back(b);
        adjList[b].push_back(a);
    }
    
    while (adjList[1].size() != 0) { 
        cont++;
        dfs_num.assign(n + 1, INF); 
        int mayor = -1, pos = -1;
        
        for (int i = 2; i < adjList.size(); i++) {
            int x = adjList[i].size();
            if (x > mayor) {
                mayor = x;
                pos = i;
            }
        }
        
        for (int i = 1; i < adjList.size(); i++) {
            adjList[i].erase(remove(adjList[i].begin(), adjList[i].end(), pos), adjList[i].end());
        }
        adjList[pos].clear();
        
        DFS(source);
        
        for (int i = 1; i < dfs_num.size(); i++) {
            if (dfs_num[i] == INF) {
                adjList[i].clear();
            }
        }
 
    }
    
    cout<<cont+1<<"\n";
    return 0;
}
