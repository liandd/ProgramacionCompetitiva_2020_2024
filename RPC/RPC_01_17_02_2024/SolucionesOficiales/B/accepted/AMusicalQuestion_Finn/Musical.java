import java.io.*;
import java.util.*;

/**
 * Use dynamic programming. Keep track of whether or not we can reach i minutes
 * on disk 1 and j minutes on disk 2.
 *
 * @author Finn Lidbetter
 */

public class Musical {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        String[] s = br.readLine().split(" ");
        int C = Integer.parseInt(s[0]);
        int n = Integer.parseInt(s[1]);
        // dp[i][j] is true iff we can get i minutes used on disk 1 and 
        // j minutes used on disk 2.
        boolean[][] prev = new boolean[C+1][C+1];
        prev[0][0] = true;
        s = br.readLine().split(" ");
        for (int i=0; i<n; i++) {
            int val = Integer.parseInt(s[i]);
            boolean[][] curr = new boolean[C+1][C+1];
            for (int c1=0; c1<=C; c1++) {
                for (int c2=0; c2<=C; c2++) {
                    if (prev[c1][c2]) {
                        curr[c1][c2] = true;
                        if (c1+val<=C) {
                            curr[c1+val][c2] = true;
                        }
                        if (c2+val<=C) {
                            curr[c1][c2+val] = true;
                        }
                    }
                }
            }
            prev = curr;
        }
        int best = 0;
        int bestDiff = C;
        int bestD1 = 0;
        int bestD2 = 0;
        for (int i=0; i<=C; i++) {
            for (int j=0; j<=C; j++) {
                if (prev[i][j] && i+j>best) {
                    best = i + j;
                    bestD1 = (int)Math.max(i, j);
                    bestD2 = (int)Math.min(i, j);
                    bestDiff = bestD1 - bestD2;
                } else if (prev[i][j] && i + j == best) {
                    int d1 = (int)Math.max(i, j);
                    int d2 = (int)Math.min(i, j);
                    if (d1 - d2 < bestDiff) {
                        bestDiff = d1 - d2;
                        bestD1 = d1;
                        bestD2 = d2;
                    }
                }
            }
        }
        System.out.println(bestD1 + " " + bestD2);
    }
}
