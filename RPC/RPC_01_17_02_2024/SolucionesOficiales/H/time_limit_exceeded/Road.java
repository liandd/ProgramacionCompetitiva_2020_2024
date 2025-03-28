import java.util.*;
import java.io.*;

/** DFS solution which should be way too slow. */
public class Road {
    public static void main(String[] args) throws IOException {
        
        // Read and store input
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String[] line = br.readLine().split(" ");
        int n = Integer.parseInt(line[0]);
        int m = Integer.parseInt(line[1]);
        int a = Integer.parseInt(line[2]) - 1;
        int b = Integer.parseInt(line[3]) - 1;
        int[][] dist = new int[n][n];
        int totalLength = 0;
        for (int i = 0; i < m; i++) {
            line = br.readLine().split(" ");
            int u = Integer.parseInt(line[0]) - 1;
            int v = Integer.parseInt(line[1]) - 1;
            int l = Integer.parseInt(line[2]);
            dist[u][v] = dist[v][u] = l;
            totalLength += l;
        }
  
        // Find and out the answer
        paved = new boolean[n][n];
        dfs(dist, 0, a, b); 
        int unpaved = totalLength;
        for (int i = 0; i < dist.length; i++) {
          for (int j = i + 1; j < dist.length; j++) {
            if (paved[i][j]) {
              unpaved -= dist[i][j];
            }
          }
        }
        System.out.println(unpaved);
    }

    static int shortest = Integer.MAX_VALUE;
    static boolean[][] paved;
    static void dfs(int[][] dist, int sum, int u, int b) {
      if (u == b) {
        if (sum < shortest) {
          shortest = sum;
          for (int i = 0; i < dist.length; i++) {
            Arrays.fill(paved[i], false);
          }
        }
        if (sum <= shortest) {
          for (int i = 0; i < dist.length; i++) {
            for (int j = i + 1; j < dist.length; j++) {
              if (dist[i][j] < 0) {
                paved[i][j] = true;
              }
            }
          }
        }
        return;
      }

      for (int v = 0; v < dist.length; v++) {
        if (dist[u][v] > 0) {
          int d = dist[u][v];
          dist[u][v] = dist[v][u] = -d; // Mark edge as visited using a negative value
          dfs(dist, sum + d, v, b);
          dist[u][v] = dist[v][u] = d; // Backtrack
        }
      }
    }
}
