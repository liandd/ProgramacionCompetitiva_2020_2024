import java.util.*;
import java.io.*;

class Edge {
  public int from,to,cost;

  public Edge(int from, int to, int cost) {
    this.from = from; this.to = to; this.cost = cost;
  }
}

class Node {
  public int id;
  public int dist[], parent[]; //results of three different searches
  public ArrayList<Integer> nbr;
  public ArrayList<Integer> rnbr;

  public Node(int id) {
    this.id = id;
    dist = new int[3];
    Arrays.fill(dist,Integer.MAX_VALUE/3);
    parent = new int[3];
    Arrays.fill(parent,-1);
    nbr = new ArrayList<Integer>();
    rnbr = new ArrayList<Integer>();
  }
}

public class Table {
  public static BufferedReader in;
  public static int w,h;
  public static int maxV;
  public static int[][] table;
  public static Node[] graph;
  public static ArrayList<Integer> top;
  public static boolean visited[];
  public static int numv[];
  public static int src, sink;
  public static ArrayList<PriorityQueue<Node>> pq;

  public static void main(String[] args) throws IOException {
    try {
      in = new BufferedReader(new InputStreamReader(System.in));
      String line = in.readLine();
      StringTokenizer st = new StringTokenizer(line);
      h = Integer.parseInt(st.nextToken());
      w = Integer.parseInt(st.nextToken());

      table = new int[h][w];
      maxV = 0;
      for (int i = 0; i < h; i++) {
        line = in.readLine();
        st = new StringTokenizer(line);
        for (int j = 0; j < w; j++) {
          // subtract 1 from all inputs to get zero-based:
          table[i][j] = Integer.parseInt(st.nextToken()) - 1;
          maxV = Math.max(maxV,table[i][j]+1);
        }
      }
    } catch(IOException e) {
      System.err.println(e);
    }

    maxV += 2; // "+2" for source (graph[maxV-2]) and sink (graph[maxV-1])
    boolean used[] = new boolean[maxV]; // so we don't duplicate nodes
    Arrays.fill(used,false);
    graph = new Node[maxV];
    src = maxV-2;
    sink = maxV-1;
    graph[src] = new Node(src);
    graph[sink] = new Node(sink);
    // create the graph:
    for (int i = 0; i < h; i++) {
      for (int j = 0; j < w; j++) {
        int t = table[i][j];
        int below;
        if (i < h-1) {
          below = table[i+1][j];
        }
        else {
          below = sink; // goes to "sink" node
        }
        if (!used[t]) {
          graph[t] = new Node(t);
          used[t] = true;
        }
        if (t != below && !graph[t].nbr.contains(below)) {
          graph[t].nbr.add(below);
          if (i < h-1 && !used[below]) {
            graph[below] = new Node(below);
            used[below] = true;
          } 
          graph[below].rnbr.add(t);
        }
      }
    }

    // Point the source to the top table element(s):
    graph[src].nbr.add(table[0][0]);
    if (table[0][w-1] != table[0][0]) {
      graph[src].nbr.add(table[0][w-1]);
    }

    int numtop = graph[src].nbr.size();


      pq = new ArrayList<PriorityQueue<Node>>();
      pq.add( new PriorityQueue<Node>(new Comparator<Node>() {
           public int compare(Node x, Node y) {
             return x.dist[0]-y.dist[0];
           }
         }));
      pq.add(new PriorityQueue<Node>(new Comparator<Node>() {
           public int compare(Node x, Node y) {
             return x.dist[1]-y.dist[1];
           }
         }));
      pq.add(new PriorityQueue<Node>(new Comparator<Node>() {
           public int compare(Node x, Node y) {
             return x.dist[2]-y.dist[2];
           }
         }));

    // Easy case: only one top piece
    if (numtop == 1) {
      // only one top piece, so find shortest path to sink:
      visited = new boolean[maxV];
      reset();
      pq.get(0).add(graph[src]);
      graph[src].dist[0] = 0;
      dijk(src,src,sink,"",0);
       System.out.println(graph[sink].dist[0]-1);

    } else {

    // Hard(er) case: two top pieces

      int t1 = graph[src].nbr.get(0);
      int t2 = graph[src].nbr.get(1);

      int best = Integer.MAX_VALUE/3;
      // Find shortest paths from t1 to all vertices:
      visited = new boolean[maxV];
      graph[t1].dist[0] = 0;
      pq.get(0).add(graph[t1]);
      dijk(t1,t1,sink,"",0);
      reset();
      graph[t2].dist[1] = 0;
      pq.get(1).add(graph[t2]);
      dijk(t2,t2,sink,"",1);
      reset();
      graph[sink].dist[2] = 0;
      pq.get(2).add(graph[sink]);
      dijk(sink,sink,src,"",2);
      
      best = graph[sink].dist[0]+graph[sink].dist[1];
      for (int i = 0; i < maxV; i++) {
         best = Math.min(best, graph[i].dist[0]+graph[i].dist[1]+graph[i].dist[2]); 
      }
      System.out.println(best);
    }
  }


  public static void dijk(int src, int start, int sink, String ind, int m) {
    visited[start] = true;
    Node s = graph[start];
    ArrayList<Integer>nbr = s.nbr;
    if (m == 2) nbr = s.rnbr;
    for (int e: nbr) {
      if (visited[e]) continue; // already done
      Node t = graph[e];
      if (s.dist[m] + 1 < t.dist[m]) {
        t.dist[m] = s.dist[m] + 1;
        t.parent[m] = start;
        pq.get(m).remove(t);
        pq.get(m).add(t);
      }
    }
    if (!pq.get(m).isEmpty()) {
      dijk(src,pq.get(m).poll().id, sink,ind+"  ",m);
    }
  }

  public static void reset() {
    //pq.clear();
    for (int i = 0; i < maxV; i++) {
      //graph[i].dist = Integer.MAX_VALUE/3;
      //graph[i].parent = -1;
      visited[i] = false;
    }
  }

  public static void display(int m) {
    for (int i = 0; i < maxV; i++) {
      System.out.println((i+1)+": "+graph[i].dist[m]);
    }
  }
}
