#include<iostream>
#include<vector>
using namespace std;

const int INF = 1000000000;

class Edge
{
public:
	int cost;
	int w;

	Edge(int ww, int ccost)
	{
		w = ww;
		cost = ccost;
	}
};

class Vertex
{
public:
	vector<Edge> adj;
	bool visited;
	int dist[2];		// dist[0] - distance from house; dist[1] - distance from office
};

class Graph
{
public:
	Vertex *vertices;
	int nVerts;

	Graph(int n)
	{
		nVerts = n;
		vertices = new Vertex[n+1];
	}

	void addEdge(int v, int w, int cost)
	{
		Edge* e = new Edge(w, cost);
		vertices[v].adj.push_back(*e);
		e = new Edge(v, cost);
		vertices[w].adj.push_back(*e);
	}

	void dijkstra(int source, int index)
	{
		init(index);
		vertices[source].dist[index] = 0;
		int numFound = 0;

		while (true) {
//			for(int i=0; i<3; i++)
//				System.out.println("distance from " + index + " to " + i + ": " + vertices[i].dist[index]);
			int v = getMinDistUnvisited(index);
			if (v == -1)
				return;
			vertices[v].visited = true;
			if (++numFound == nVerts)
				return;
			for(Edge e : vertices[v].adj) {
				int w = e.w;
				if (!vertices[w].visited && vertices[v].dist[index]+e.cost < vertices[w].dist[index]) {
					vertices[w].dist[index] = vertices[v].dist[index]+e.cost;
				}
			}
		}
	}

	void init(int index)
	{
		for(int i=0; i<=nVerts; i++) {
			vertices[i].dist[index] = INF;
			vertices[i].visited = false;
		}
	}

	int getMinDistUnvisited(int index)
	{
		int v = -1, dist = INF;
		for(int i=0; i<=nVerts; i++)
			if (!vertices[i].visited && vertices[i].dist[index] < dist) {
				dist = vertices[i].dist[index];
				v = i;
			}
		return v;
	}

	void print()
	{
		for(int i=0; i<nVerts; i++) {
			Vertex v = vertices[i];
			cout << i << ":";
			for(Edge e : v.adj) {
				cout << " " << e.w << "(" << e.cost << ")";
			}
			cout << endl;
		}
	}
};

int main() {

    int n, m, house, office;

    cin >> n >> m >> house >> office;
    house--;
    office--;

    Graph g(n);
    for(int i=0; i<m; i++) {
        int v1, v2, cost;
        cin >> v1 >> v2 >> cost;
        v1--;
        v2--;
        g.addEdge(v1, v2, cost);
    }
//		g.print();
    g.dijkstra(house, 0);
    g.dijkstra(office, 1);
/*
    for(int i=0; i<n; i++) {
        System.out.println("dist from " + house + " to " + i + ": " + g.vertices[i].dist[0]);
    }
    for(int i=0; i<n; i++) {
        System.out.println("dist from " + office + " to " + i + ": " + g.vertices[i].dist[1]);
    }
/**/
    int savings = 0;
    int minDist = g.vertices[office].dist[0];
    for(int i=0; i<n; i++) {
        Vertex v = g.vertices[i];
        for(Edge e: v.adj) {
            if (e.w < i)
                continue;
            if (g.vertices[i].dist[0] == INF || g.vertices[e.w].dist[1] == INF)
                savings += e.cost;
            else if (g.vertices[i].dist[0] + e.cost + g.vertices[e.w].dist[1] != minDist &&
                     g.vertices[e.w].dist[0] + e.cost + g.vertices[i].dist[1] != minDist)
                savings += e.cost;
        }
    }
    cout << savings << endl;

}
