// Solution to "A Musical Question" (Scanner version)
import java.util.*;
 
public class Musical {
  public static void main (String[] args) {
    Scanner in = new Scanner(System.in);
    int c = in.nextInt(); // capacity
    int n = in.nextInt(); // capacity

    boolean[][][] dp = new boolean[n+1][c+1][c+1];
    int w[] = new int[n+1];
    w[0] = 0;
    for (int i = 1; i <= n; i++)
      w[i] = in.nextInt();
       
    for (int i = 0; i < n ; i++)
      for (int j = 0; j < c ; j++)
        Arrays.fill(dp[i][j], false);
         
    int m = 0;
    dp[0][0][0] = true;
    for (int i = 1; i <= n; i++)
      for (int j = 0; j <= c; j++)
        for (int k = 0; k <= c; k++) {
          dp[i][j][k] = dp[i-1][j][k] ||
               (j-w[i] >= 0 && dp[i-1][j-w[i]][k]) ||
               (k-w[i] >= 0 && dp[i-1][j][k-w[i]]);
          if (dp[i][j][k]) m = Math.max(m,j+k);
        }
    int lim = Math.min(c,m);
    int diff = m;
    int x = 0, y = m;
    for (int i = m-lim; i <= lim; i++) {
      if (dp[n][i][m-i] && Math.abs(m-2*i) < diff) {
        diff = Math.abs(m-2*i);
        x = i; y = m-i;
      }
    }
    System.out.println(Math.max(x,y)+" "+Math.min(x,y));
  }
}
