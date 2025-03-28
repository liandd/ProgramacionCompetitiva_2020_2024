import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.List;
import java.util.StringTokenizer;


/**
 * ICPC - CTU Open Contest 2023
 * Sample Solution: Movers
 */

public class MoversPC {
  StringTokenizer st = new StringTokenizer("");
  BufferedReader input = new BufferedReader(new InputStreamReader(System.in));
  boolean hasNextToken() {
    try {
      while (!st.hasMoreTokens()) {
        String line = input.readLine();
        if (line == null) return false;
        st = new StringTokenizer(line);
      }
    } catch (IOException ex) { throw new RuntimeException(ex); }
    return true;
  }
  String nextToken() {
    return (!hasNextToken()) ? null : st.nextToken();
  }
  int nextInt() {
    return Integer.parseInt(nextToken());
  }
  public static void main(String[] args) {
    new MoversPC().run();
  }

  List<List<Integer>> graph;
  List<List<Integer>> heavyNeigh;
  static final int HEAVINESS = 300;

  void run() {
    int n = nextInt(), m = nextInt(), q = nextInt();
    int[] deg = new int[n];
    int[] diff = new int[n]; // diff (desks - monitors) in the vertex
    int[] diffHood = new int[n]; // sum of the diffs of non-heavy neighbors
    boolean[] heavy = new boolean[n]; // has the vertex many neighbors?
    graph = new ArrayList<>(n); // lists of neighbors
    heavyNeigh = new ArrayList<>(n); // lists of heavy neighbors
    for (int i = 0; i < n; ++i) {
      graph.add(new ArrayList<>());
      heavyNeigh.add(new ArrayList<>());
    }
    for (int i = 0; i < n; ++i) diff[i] += nextInt();
    for (int i = 0; i < n; ++i) diff[i] -= nextInt();
    for (int i = 0; i < m; ++i) { 
      int a = nextInt() - 1, b = nextInt() - 1;
      deg[a]++; deg[b]++;
      graph.get(a).add(b); graph.get(b).add(a);
    }
    for (int a = 0; a < n; ++a) {
      heavy[a] = (deg[a] > HEAVINESS);
      for (int b : graph.get(a)) {
        if (deg[b] > HEAVINESS) {
          heavyNeigh.get(a).add(b);
        }
        else {
          diffHood[a] += diff[b];
        }
      }
    }
    for (int step = 0; step < q; ++step) {
      String operation = nextToken();
      if (operation.equals("add")) {
        int cnt = nextInt();
        String what = nextToken();
        int add = (what.equals("desk") ? cnt : -cnt);
        int a = nextInt() - 1;
        diff[a] += add;
        if (!heavy[a]) {
          for (int b : graph.get(a)) {
            diffHood[b] += add;
          }
        } 
      }
      else { // check
        int a = nextInt() - 1;
        int sum = diff[a] + diffHood[a];
        for (int b : heavyNeigh.get(a)) {
          sum += diff[b];
        }
        System.out.println(sum == 0 ? "same" : (sum < 0 ? "monitors" : "desks"));
      }
    }
  }
}
