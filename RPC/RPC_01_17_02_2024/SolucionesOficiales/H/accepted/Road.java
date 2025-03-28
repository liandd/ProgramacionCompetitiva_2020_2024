import java.util.ArrayList;
import java.util.Scanner;

public class Road {

	public static void main(String[] args) {

		Scanner in = new Scanner(System.in);
		int n, m, house, office;
		
		n = in.nextInt();
		m = in.nextInt();
		house = in.nextInt() - 1;
		office = in.nextInt() - 1;
		
		Graph g = new Graph(n);
		for(int i=0; i<m; i++) {
			int v1, v2, cost;
			v1 = in.nextInt() - 1;
			v2 = in.nextInt() - 1;
			cost = in.nextInt();
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
				if (g.vertices[i].dist[0] == Integer.MAX_VALUE || g.vertices[e.w].dist[1] == Integer.MAX_VALUE)
					savings += e.cost;
				else if (g.vertices[i].dist[0] + e.cost + g.vertices[e.w].dist[1] != minDist &&
						 g.vertices[e.w].dist[0] + e.cost + g.vertices[i].dist[1] != minDist)
					savings += e.cost;
			}
		}
		System.out.println(savings);

	}
}

class Vertex
{
	public ArrayList<Edge> adj = new ArrayList<>();
	public boolean visited;
	public int [] dist = new int[2];		// dist[0] - distance from house; dist[1] - distance from office
}

class Edge
{
	public int cost;
	public int w;

	public Edge(int w, int cost)
	{
		this.w = w;
		this.cost = cost;
	}
}

class Graph
{
	public Vertex[] vertices;
	public int nVerts;

	public Graph(int n)
	{
		nVerts = n;
		vertices = new Vertex[n+1];
		for(int i = 0; i<=n; i++) {
			vertices[i] = new Vertex();
		}
	}

	public void addEdge(int v, int w, int cost)
	{
		Edge e = new Edge(w, cost);
		vertices[v].adj.add(e);
		e = new Edge(v, cost);
		vertices[w].adj.add(e);
	}

	public void dijkstra(int source, int index)
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
			if (++numFound == vertices.length)
				return;
			for(Edge e : vertices[v].adj) {
				int w = e.w;
				if (!vertices[w].visited && vertices[v].dist[index]+e.cost < vertices[w].dist[index]) {
					vertices[w].dist[index] = vertices[v].dist[index]+e.cost;
				}
			}
		}
	}

	private void init(int index)
	{
		for(int i=0; i<=nVerts; i++) {
			vertices[i].dist[index] = Integer.MAX_VALUE;
			vertices[i].visited = false;
		}
	}

	private int getMinDistUnvisited(int index)
	{
		int v = -1, dist = Integer.MAX_VALUE;
		for(int i=0; i<=nVerts; i++)
			if (!vertices[i].visited && vertices[i].dist[index] < dist) {
				dist = vertices[i].dist[index];
				v = i;
			}
		return v;
	}
	
	public void print()
	{
		for(int i=0; i<vertices.length; i++) {
			Vertex v = vertices[i];
			System.out.println(i + ":");
			for(Edge e : v.adj) {
				System.out.print(" " + e.w + "(" + e.cost + ")");
			}
			System.out.println();
		}
	}
}