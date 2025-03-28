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
  public int dist, parent;
  public ArrayList<Integer> nbr;

  public Node(int id) {
    this.id = id;
    dist = Integer.MAX_VALUE/2;
    parent = -1;
    nbr = new ArrayList<Integer>();
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
  public static PriorityQueue<Node> pq;

  public static void main(String[] args) throws IOException {
//System.out.println("INPUT:");
    try {
      in = new BufferedReader(new InputStreamReader(System.in));
      String line = in.readLine();
//System.out.println(line);
      StringTokenizer st = new StringTokenizer(line);
      h = Integer.parseInt(st.nextToken());
      w = Integer.parseInt(st.nextToken());

      table = new int[h][w];
      maxV = 0;
      for (int i = 0; i < h; i++) {
        line = in.readLine();
//System.out.println(line);
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

//System.out.println("CHECK: maxV = "+maxV);
/*
    for (int i = 0; i < h; i++) {
      for (int j = 0; j < w; j++) {
        System.out.printf("%2d ",table[i][j]);
      }
      System.out.println();
    }
*/

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
//System.out.println("Creating node "+t);
          graph[t] = new Node(t);
          used[t] = true;
        }
        if (t != below && !graph[t].nbr.contains(below)) {
          graph[t].nbr.add(below);
        }
      }
    }

    // Point the source to the top table element(s):
    graph[src].nbr.add(table[0][0]);
    if (table[0][w-1] != table[0][0]) {
      graph[src].nbr.add(table[0][w-1]);
    }
/*
System.out.println("Initial graph:");
print("src : ",maxV-2);
for (int i = 0; i < maxV-2; i++) {
  print("",i);
}
print("sink: ",maxV-1);
*/

    int numtop = graph[src].nbr.size();

/*
    System.out.print("Top vertices: "+(1+graph[src].nbr.get(0)));
    if (numtop > 1) {
      System.out.print(" "+(1+graph[src].nbr.get(1)));
    }
    System.out.println();
*/

    pq = new PriorityQueue<Node>(new Comparator<Node>() {
           public int compare(Node x, Node y) {
             return x.dist-y.dist;
           }
         });

    // Easy case: only one top piece
    if (numtop == 1) {
      // only one top piece, so find shortest path to sink:
//System.out.println("=============\nEasy case:");
      visited = new boolean[maxV];
      reset();
//      pq.add(graph[src]);
      graph[src].dist = 0;
// System.out.printf("===\nDijkstra from source (%d) to sink (%d):\n",src,sink);
      dijk(src,src,sink,"");
//      System.out.println("ANSWER: "+(graph[maxV-1].dist-1));
       System.out.println(graph[sink].dist-1);

/*
        ArrayList<Integer> blocks = new ArrayList<Integer>();
        int p = graph[sink].parent;
        while (p != src && p >= 0) {
          //System.out.printf(" %d",(p+1));
          blocks.add(p);
          p = graph[p].parent;
        }
        Collections.sort(blocks);
	for (int i = 0; i < blocks.size()-1; i++) {
          System.out.print((1+blocks.get(i))+" ");
        }
        System.out.println(1+blocks.get(blocks.size()-1));
*/
      } else {

    // Hard(er) case: two top pieces

//System.out.println("=============\nHard case:");
     // First, make two DFS passes through the graph, each starting at a
     // different "top" piece. Mark all nodes reachable from both top pieces.
      visited = new boolean[maxV];
      numv = new int[maxV];
      // first pass:
//System.out.println("First DFS pass, starting at "+graph[src].nbr.get(0));
      mark(graph[src].nbr.get(0));

      Arrays.fill(visited,false);
      // second pass:
//System.out.println("Second DFS pass, starting at "+graph[src].nbr.get(1));
      mark(graph[src].nbr.get(1));

      // create a list of all nodes reachable from both top pieces:
      ArrayList<Integer> both = new ArrayList<Integer>();
      for (int i = 0; i < maxV; i++) {
        if (numv[i] == 2) both.add(i);
      }
/*
      System.out.println("Reachable from both:");
      for (int i: both) {
        System.out.print(" "+(i+1));
      }
      System.out.println();
*/

    // Now we look at each vertex reachable from both top pieces and compute
    // shortest disjoint paths to top pieces and shortest path to sink node.

    int best = Integer.MAX_VALUE; // best solution value
    ArrayList<Integer> bestpath = new ArrayList<Integer>();

    for (int s: both) {
      int d1,d2,d3;
/*
      pq = new PriorityQueue<Node>(new Comparator<Node>() {
             public int compare(Node x, Node y) {
               return x.dist-y.dist;
             }
           });
*/

      int t1 = graph[src].nbr.get(0);
      int t2 = graph[src].nbr.get(1);
/*
      for (int i = 0; i < maxV; i++) {
        graph[i].dist = Integer.MAX_VALUE/2;
        graph[i].parent = -1;
      }
*/
      reset();

//      pq.add(graph[t1]);
//      Arrays.fill(visited,false);
      graph[t1].dist = 0;
//System.out.printf("===\nDijkstra from first top piece (%d) to node %d:\n",t1+1,s+1);
      dijk(t1,t1,s,"");

      // Preserve the path from t1 to s:
      ArrayList<Integer> first = new ArrayList<Integer>();
      int p = graph[s].parent;
//System.out.print("First list: ");
      while (p >= 0) {
        first.add(p);
//System.out.print(" "+p);
        p = graph[p].parent;
      }
//System.out.println();

      d1 = graph[s].dist;
/*
      pq.clear();
      for (int i = 0; i < maxV; i++) {
        graph[i].dist = Integer.MAX_VALUE/2;
        graph[i].parent = -1;
      }
*/
      reset();

//      pq.add(graph[t2]);
//      Arrays.fill(visited,false);
      // But ... we want to remember nodes used in first path
      int s1 = s;
      for (int q: first) {
        graph[s1].parent = q;
        visited[q] = true;
        s1 = q;
      }

      graph[t2].dist = 0;
//System.out.printf("===\nDijkstra from second top piece (%d) to node %d:\n",t2+1,s+1);
      dijk(t2,t2,s,"");

      // Preserve the path from t2 to s:
      ArrayList<Integer> second = new ArrayList<Integer>();
      p = graph[s].parent;
//System.out.print("First list: ");
      while (p >= 0) {
        second.add(p);
//System.out.print(" "+p);
        p = graph[p].parent;
      }
//System.out.println();

      d2 = graph[s].dist;

/*
      pq.clear();
      for (int i = 0; i < maxV; i++) {
        graph[i].dist = Integer.MAX_VALUE/2;
        graph[i].parent = -1;
      }
*/
//      pq.add(graph[s]);
//      Arrays.fill(visited,false);
      reset();
      graph[s].dist = 0;
//System.out.printf("===\nDijkstra from %d to sink node %d:\n",s+1,sink);

      dijk(s,s,sink,"");
      d3 = graph[sink].dist;
//System.out.printf("d(%d,%d) = %d; d(%d,%d) = %d; d(%d,%d) = %d; total = %d\n",
//        (t1+1),(s+1),d1,(t2+1),(s+1),d2,(s+1),maxV,d3,(d1+d2+d3));
      if (best > d1+d2+d3) {
        best = d1+d2+d3;
        bestpath = bp(first,second,s);
      }
    }
    System.out.println(best);
/*
    for (int i:bestpath) {
      System.out.print((i+1)+" ");
    }
    System.out.println();
*/
  }
  }

  public static ArrayList<Integer> bp(ArrayList<Integer> t1,
        ArrayList<Integer> t2, int s) {
    ArrayList<Integer> b = new ArrayList<Integer>();
    int p = graph[sink].parent;
    while (p >= 0 && p != s) {
      b.add(p);
      p = graph[p].parent;
    }
    b.add(s);
    b.addAll(t1);
    b.addAll(t2);
    p = graph[s].parent;
    while (p >= 0 && p != graph[src].nbr.get(1)) {
      b.add(p);
      p = graph[p].parent;
    }
    return b;
  }
 
public static void print(String info, int i) {
  if (info.length() > 0)
    System.out.print(info);
  else
    System.out.printf("%4d: ",(i+1));
  for (int j:graph[i].nbr) {
    System.out.printf(" %2d (%d,%d,%d)",(j+1),graph[j].id,graph[j].dist,graph[j].parent+1);
  }
  System.out.println();
}
  

  // DFS to mark all nodes reachable from either of the top pieces
  public static void mark(int start) {
//System.out.println("DFS visiting "+(start+1));
    visited[start] = true;
    numv[start]++;
    for (int e: graph[start].nbr) {
      if (visited[e]) continue;
//System.out.println("  DFS trying to visit "+(e+1));
      mark(e);
    }
  }

  public static void dijk(int src, int start, int sink, String ind) {
//    System.out.println(ind+"dijk visiting node "+(start+1));
    visited[start] = true;
    Node s = graph[start];
    for (int e: s.nbr) {
//      System.out.printf(ind+"   Considering edge %d --> %d\n",(start+1),(e+1));
      if (visited[e]) continue; // already done
//      System.out.printf(ind+"   %d is unused, dist(%d,%d)+dist(%d,%d) = %d\n",
//           (e+1),0,start,start,(e+1),(s.dist+1));
      Node t = graph[e];
      if (s.dist + 1 < t.dist) {
        t.dist = s.dist + 1;
        t.parent = start;
//        System.out.printf(ind+"      Updating %d.dist to %d, %d.parent to %d\n",
//           (e+1),t.dist,(e+1),(t.parent+1));
 int temp = pq.size();
        pq.remove(t);
        pq.add(t);
if (pq.size() > temp) {
//System.out.println(ind+"      added "+(e+1)+" to queue");
}
      }
    }
    if (!pq.isEmpty()) {
      dijk(src,pq.poll().id, sink,ind+"  ");
    }
  }

  public static void reset() {
    pq.clear();
    for (int i = 0; i < maxV; i++) {
      graph[i].dist = Integer.MAX_VALUE/2;
      graph[i].parent = -1;
      visited[i] = false;
    }
  }
}

/*
-----------------------------------------------------------------------------


public class TryDijk {
  public static int n,m;
  public static Node[] graph;
  public static Scanner in;
  public static boolean[] used;

  public static void main(String[] args) {
    in = new Scanner(System.in);
    n = in.nextInt();
    m = in.nextInt();
    graph = new Node[n];
    used = new boolean[n];
    Arrays.fill(used,false);
    for (int i = 0; i < n; i++) {
      graph[i] = new Node(i);
    }
    for (int i = 0; i < m; i++) {
      int f = in.nextInt();
      int t = in.nextInt();
      int c = in.nextInt();
      graph[f].nbr.add(new Edge(f,t,c));
    }
    graph[0].dist = 0;
    pq = new PriorityQueue<Node>(new Comparator<Node>() {
             public int compare(Node x, Node y) {
               return x.dist-y.dist;
             }
           });

    pq.add(graph[0]);

    dijk(0,0,n-1,"");

    System.out.printf("Distances and paths:\n");
    for (int i = 0; i < n; i++) {
      System.out.printf("%2d: dist = %d, path = ",i,graph[i].dist);
      int p = graph[i].parent;
      while (p >= 0) {
        System.out.printf(" %d",p);
        p = graph[p].parent;
      }
      System.out.println();
    }
System.out.println("=============");

    Arrays.fill(used,false);
    int p = graph[n-1].parent;
    while (p >= 0) {
      used[p] = true;
      p = graph[p].parent;
    }
    used[0] = false;
System.out.print("Used nodes:");
for (int i = 0; i < n; i++)
  if(used[i]) System.out.print(" "+i);
System.out.println();

    // Reset distance, parent info for each remaining node:
    for (int i = 1; i < n; i++) {
      if (!used[i]) {
        graph[i].dist = Integer.MAX_VALUE/2;
        graph[i].parent = -1;
      }
    }

    pq.clear();
    pq.add(graph[0]);

    dijk(0,0,n-1,"");

    System.out.printf("Distances and paths:\n");
    for (int i = 0; i < n; i++) {
      System.out.printf("%2d: dist = %d, path = ",i,graph[i].dist);
      p = graph[i].parent;
      while (p >= 0) {
        System.out.printf(" %d",p);
        p = graph[p].parent;
      }
      System.out.println();
    }
  }
      
}
*/
