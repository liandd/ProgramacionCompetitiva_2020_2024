#include <bits/stdc++.h>

using namespace std;

#define INF 1e9
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
vector <vii> adjList;
vi dist;
bool mat[505][505];

void dijkstra(int s){
    dist[s]=0;
    priority_queue<ii, vii, greater<ii> > pq; pq.push(ii(0, s));
    while(!pq.empty()){
        ii front = pq.top(); pq.pop();
        int d = front.first, u = front.second;
        if(d>dist[u]) continue;
        for(int j=0; j<adjList[u].size(); j++){
            ii v = adjList[u][j];
            //printf("mat[u][adjList[u][j].first: %d - mat[adjList[u][j].first][u]: %d\n", mat[u][adjList[u][j].first], mat[adjList[u][j].first][u]);
            if(mat[u][adjList[u][j].first] && mat[adjList[u][j].first][u]) v.second=0;
            if (dist[u]+v.second<dist[v.first]){
                dist[v.first]=dist[u]+v.second;
                pq.push(ii(dist[v.first], v.first));
            }
        }
    }

}

int main(){
    int n, e, k;
    while(scanf("%d %d", &n, &e)){
        if(!n && !e) break;
        adjList.assign(n, vii());
        memset(mat, false, sizeof mat);
        while(e--){
            int a, b, w;
            scanf("%d %d %d", &a, &b, &w);
            adjList[a-1].push_back(ii{b-1, w});
            mat[a-1][b-1]=true;
        }
        scanf("%d", &k);
        while(k--){
            int a, b;
            dist.assign(n, INF);
            scanf("%d %d", &a, &b);
            //printf("salida: ");
            if(mat[a-1][b-1] && mat[b-1][a-1]) printf("0\n");
            else{
                dijkstra(a-1);
                if(dist[b-1]!=INF) printf("%d\n", dist[b-1]);
                else printf("Nao e possivel entregar a carta\n");
            }
        }
        printf("\n");
    }



return 0;
}
