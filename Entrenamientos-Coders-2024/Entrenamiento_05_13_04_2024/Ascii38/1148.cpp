#include<bits/stdc++.h>
using namespace std;

#define INF 1001001001
typedef pair<int,int> ii;

int dijkstra(vector<ii> ady[], int origen, int destino, int tam){
   priority_queue<ii> pq;
   int dist[tam + 1];
   fill(dist, dist + tam, INF);
   dist[origen] = 0;
   pq.push(ii(0, origen));
   while(!pq.empty()){
      int a = pq.top().first;
      int b = pq.top().second;
      pq.pop();
      if(a != dist[b]) continue;
      for(int j = 0; j < (int)ady[b].size(); j++){
         ii v = ady[b][j];
	 int peso = v.first;
	 int adj = v.second;
	 if(a + peso < dist[adj]){
	    dist[adj] = a + peso;
	    pq.push(ii(dist[adj],adj));
	 }
      }
   }
   return dist[destino] == INF ? -1 : dist[destino];
}
int main(){
   int n = 0, e = 0;
   while((cin>>n>>e) && n){
      vector<ii> grafito[n];
      bool caminos[502][502] = {{},{}};
      for(int i = 0; i < e; i++){
         int a = 0, b = 0, w = 0;
	 cin>>a>>b>>w;
	 a--, b--;
	 grafito[a].push_back(ii(w,b));
	 caminos[a][b] = true;
	 if(caminos[b][a]){
            grafito[a][(int)grafito[a].size()-1].first = 0;
	    int j = 0;
	    while(grafito[b][j].second != a)j++;
	    grafito[b][j].first = 0;
	 }
      }
      int t = 0;
      cin>>t;
      while(t--){
         int a = 0, b = 0;
	 cin>>a>>b;
	 a--,b--;
	 int res = 0;
	 res = dijkstra(grafito,a,b,n);
	 (res == -1) ? cout<<"Nao e possivel entregar a carta\n" : cout<<res<<"\n";
      }
      puts("");
   }

}
