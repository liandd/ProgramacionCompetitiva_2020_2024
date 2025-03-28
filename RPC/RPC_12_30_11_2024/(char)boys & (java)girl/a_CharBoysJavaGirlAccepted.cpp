#include <bits/stdc++.h>
using namespace std;
#define INF -1
#define fast ios_base::sync_with_stdio(0);cin.tie(0);

/*typedef pair <int, int> ii;
typedef vector <ii> vii;*/
typedef vector <int> vi; //Vector base para adjList sin pesos
vector <vi> adjList;
vi dist;
vi dfs_num;
int source, n, e;
int r;
void print(std::vector<int> const &input)
{
    std::copy(input.begin(),
            input.end(),
            std::ostream_iterator<int>(std::cout, " "));
    cout<<endl;
}

void DFS(int u){
    r++;
    dfs_num[u]=1;
    for(int j=0; j<adjList[u].size(); j++){
        int v=adjList[u][j];
        if(dfs_num[v]==INF) DFS(v);
    }
}

void BFS(){
    dist[source]=0;//El bfs guarda las distancias que hay del source a los demás nodos, por lo que el nodo de origen consigo mismo no hay distancias.
    queue <int> q; q.push(source); //Ingresa un 0, tener en cuenta que la cola es FIFO, first in, first out
    while(!q.empty()){
        int u = q.front(); q.pop();
        for(int j = 0; j < (int)adjList[u].size(); j++){
            if(dist[j]!=INF) continue;
            dist[j]=dist[u]+1;
            q.push(j);
        }
        cout<<"Pasada: "<<u<<endl;
		print(dist);
    }
}


int main(){
    fast
    //int n, e;
    cin>>n>>e;

    adjList.assign(n, vi(0, 0));
    dist.assign(n, INF);
    dfs_num.assign(n, INF);


    source=0;
    while(e--){
        int a, b;
        cin>>a>>b;
        a = a-1;
        b = b-1;
        adjList[a].push_back(b);
        adjList[b].push_back(a);
    }


   int aux =-1;
        for (int i = 0; i < dfs_num.size();i++){
            if(dfs_num[i]==INF){
                DFS(i);
                if(r> aux){
                    aux = r;
                }
                r =0;
            }
        }
        cout<<aux<<"\n";

return 0;
}
