#include <bits/stdc++.h>
using namespace std;

#define INF -1

typedef vector<int> vi; // Vector base para adjList sin pesos
typedef vector<vector<int>> vii;

vii adjList;   // Lista de adyacencia
vi dfs_num;   // Vector para DFS
vi dist;      // Vector para BFS
int source, n, e;

void print(std::vector<int> const &input) {
    std::copy(input.begin(),
              input.end(),
              std::ostream_iterator<int>(std::cout, " "));
    cout << endl;
}

void DFS(int u) {
    dfs_num[u] = 1;
    for (int j = 0; j < adjList[u].size(); j++) {
        int v = adjList[u][j];
        if (dfs_num[v] == INF)
            DFS(v);
    }
}

void BFS() {
    dist[source] = 0; // El BFS guarda las distancias que hay del source a los demás nodos
    queue<int> q;     // FIFO, first in, first out
    q.push(source);   // Ingresamos el nodo fuente

    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (int j = 0; j < adjList[u].size(); j++) {
            int v = adjList[u][j];
            if (dist[v] != INF) continue; // Si ya ha sido visitado, lo saltamos
            dist[v] = dist[u] + 1;
            q.push(v);
        }
    }
    cout << "Pasada: " << endl;
    print(dist);
}

int main() {
    cin >> n >> e; // Ingresar número de nodos y aristas

    adjList.assign(n, vi(0, 0));  // Inicializar lista de adyacencia
    dist.assign(n, INF);          // Inicializar vector de distancias con INF
    dfs_num.assign(n, INF);       // Inicializar vector para DFS con INF

    print(dist); // Imprimir distancias iniciales

    source = 0; // Nodo de origen

    // Leer las aristas
    while (e--) {
        int a, b;
        cin >> a >> b;
        adjList[a].push_back(b);
        adjList[b].push_back(a);
    }

    // DFS(0);
    BFS();

    return 0;
}
