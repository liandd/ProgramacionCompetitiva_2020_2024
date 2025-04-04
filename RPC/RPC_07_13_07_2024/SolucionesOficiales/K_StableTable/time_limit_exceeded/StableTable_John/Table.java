import java.util.ArrayList;
import java.util.Scanner;

public class Table {

	public static final int MAXP = 100;
	public static final int MAXD = 100;

	public static int[][] grid = new int[MAXD][MAXD];

	public static void main(String[] args) {

		long start = System.nanoTime();
		Scanner in = new Scanner(System.in);
		int rows = in.nextInt();
		int cols = in.nextInt();
		int maxV = 0;
		int top1, top2;
		for(int r=0; r<rows; r++)
			for(int c=0; c<cols; c++) {
				grid[r][c] = in.nextInt();
				if (grid[r][c] > maxV)
					maxV = grid[r][c];

			}
		top1 = grid[0][0];
		int cc=1;
		while (cc < cols && grid[0][cc] == top1)
			cc++;
		if (cc == cols)
			top2 = -1;
		else
			top2 = grid[0][cc];
		Graph g = new Graph(maxV);
		Graph grev = new Graph(maxV);
		for(int r=0; r<rows-1; r++)
			for(int c=0; c<cols; c++) {
				if (grid[r+1][c] != grid[r][c]) {
					g.addEdge(grid[r][c], grid[r+1][c], 1);
					grev.addEdge(grid[r+1][c], grid[r][c], 1);
				}
			}
		for(int c=0; c<cols; c++) {
			g.addEdge(grid[rows-1][c], 0, 1);			// node 0 = floor
			grev.addEdge(0, grid[rows-1][c], 1);
		}

		int minPieces = 2*maxV;
								// if only one top piece just find min distance to floor
		if (top2 == -1) {
			g.dijkstraDest(top1, 0, -1);
			minPieces = g.vertices[0].dist;
		}
		else {
								// for each vertex (including floor) check for min distances to floor, top1 and top2
			for(int v=0; v<=g.nVerts; v++) {
				grev.dijkstraDest(v,top1,top2);
				if (grev.vertices[top1].dist + grev.vertices[top2].dist >= minPieces)
					continue;
				g.dijkstraDest(v,0,-1);
				if (g.vertices[0].dist + grev.vertices[top1].dist + grev.vertices[top2].dist < minPieces) {
					//				System.out.println("Updating with v = " + v);
					minPieces = g.vertices[0].dist + grev.vertices[top1].dist + grev.vertices[top2].dist;
				}		
			}
		}
		System.out.println(minPieces);
		long end = System.nanoTime();
		//		System.out.println((end-start)/1000000000.0);
	}
}

class Vertex
{
	public ArrayList<Edge> adj = new ArrayList<>();
	public boolean visited;
	public int dist;
	public int prev;
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
		if (inList(v, w))
			return;
		Edge e = new Edge(w, cost);
		vertices[v].adj.add(e);
	}

	public boolean inList(int v, int w)
	{
		//		System.out.println(v + " " + w);
		for(Edge e: vertices[v].adj) {
			if (e.w == w)
				return true;
		}
		return false;
	}

	public void dijkstraDest(int source, int dest1, int dest2)
	{
		int numFound = (dest2 == -1) ? 1 : 0;
		init();
		vertices[source].dist = 0;

		while (true) {
			int v = getMinDistUnvisited();
			if (v == dest1 || v == dest2)
				numFound++;
			if (numFound == 2)
				break;
			vertices[v].visited = true;
			for(Edge e : vertices[v].adj) {
				int w = e.w;
				if (!vertices[w].visited && vertices[v].dist+e.cost < vertices[w].dist) {
					vertices[w].dist = vertices[v].dist+e.cost;
					vertices[w].prev = v;
				}
			}
		}
	}

	private void init()
	{
		for(int i=0; i<=nVerts; i++) {
			vertices[i].dist = nVerts+1;
			vertices[i].visited = false;
			vertices[i].prev = -1;
		}
	}

	private int getMinDistUnvisited()
	{
		int v = -1, dist = Integer.MAX_VALUE;
		for(int i=0; i<=nVerts; i++)
			if (!vertices[i].visited && vertices[i].dist < dist) {
				dist = vertices[i].dist;
				v = i;
			}
		return v;
	}
}
