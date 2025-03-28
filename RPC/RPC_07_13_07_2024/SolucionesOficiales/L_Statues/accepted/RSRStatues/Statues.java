import java.util.*;

public class Statues {
  public static int m,n;
  public static int grid[][][];
  public static ArrayList<Integer> h;

  public static void main(String[] args) {
    Scanner in = new Scanner(System.in);
    m = in.nextInt();
    n = in.nextInt();
    grid = new int[4][m][n];
    h = new ArrayList<Integer>();
    int k = 0;
    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        int temp = in.nextInt();
        grid[0][i][j] = temp;
        if (temp > 0) h.add(temp);
        grid[1][m-i-1][j] = temp;
        grid[2][i][n-j-1] = temp;
        grid[3][m-i-1][n-j-1] = temp;
      }
    }
    for (int i = 0; i < 4; i++)
    Collections.sort(h);
    int best = Integer.MAX_VALUE;
    for (int i = 0; i < 4; i++) {
      int count = solve(i);
      best = Math.min(best,count);
    }
    System.out.println(best);
  }

  public static int solve(int k) {
    int g[][] = grid[k];
    ArrayList<LinkedList<Integer>> diag = new ArrayList<LinkedList<Integer>>();
    for (int d = 0; d < m+n-1; d++) {
      LinkedList<Integer> l = new LinkedList<Integer>();
        int i = 0;
        int j = d-i;
        while (j >= n) {j--; i++;}
        while (i < m && j >= 0) {
          if (g[i][j] > 0) {
            l.add(g[i][j]);
          }
          i++;
          j--;
        }
/*
      int i = 0; int j = d-i;
      while (i >= 0 && i < m && j >= 0 && j < n) {
        if (g[i][j] > 0) {
          l.add(g[i][j]);
        }
        i++;
        j--;
      }
*/
      Collections.sort(l);
      diag.add(l);
    }
    int d = 0;
    int count = 0;
    LinkedList<Integer> l = diag.get(d);
    for (Integer v: h) {
      while (l.isEmpty()) {
        l = diag.get(++d);
      }
      int loc = l.indexOf(v);
      if (loc >= 0) {
        l.remove(loc);
      } else if (v > l.peekFirst()) {
        count++;
        l.removeFirst();
      } else {
        count++;
        l.removeLast();
      }
    }
    return count;
  }
}
