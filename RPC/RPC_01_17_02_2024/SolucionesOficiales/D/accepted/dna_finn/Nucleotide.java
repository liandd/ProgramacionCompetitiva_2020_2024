import java.io.*;
import java.util.*;

/**
 * Build up a prefix sum array for each of A,T,G,C such that queries can
 * be answered in O(1) time. 
 * Time complexity is O(n+q) for a string of length n and q queries.
 *
 * @author Finn Lidbetter
 */

public class Nucleotide {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        char[] chars = br.readLine().toCharArray();
        int n = chars.length;
        int q = Integer.parseInt(br.readLine());
        int[] aCount = new int[n+1];
        int[] tCount = new int[n+1];
        int[] gCount = new int[n+1];
        int[] cCount = new int[n+1];
        StringBuilder sb = new StringBuilder();
        for (int i=0; i<n; i++) {
            aCount[i+1] = aCount[i];
            tCount[i+1] = tCount[i];
            gCount[i+1] = gCount[i];
            cCount[i+1] = cCount[i];
            if (chars[i]=='A') {
                aCount[i+1] = aCount[i] + 1;
            }
            if (chars[i]=='T') {
                tCount[i+1] = tCount[i] + 1;
            }
            if (chars[i]=='G') {
                gCount[i+1] = gCount[i] + 1;
            }
            if (chars[i]=='C') {
                cCount[i+1] = cCount[i] + 1;
            }
        }
        for (int i=0; i<q; i++) {
            String[] s = br.readLine().split(" ");
            int lo = Integer.parseInt(s[0]);
            int hi = Integer.parseInt(s[1]);
            int as = aCount[hi] - aCount[lo - 1];
            int ts = tCount[hi] - tCount[lo - 1];
            int gs = gCount[hi] - gCount[lo - 1];
            int cs = cCount[hi] - cCount[lo - 1];
            Count[] counts = new Count[]{new Count(as, 'A'), new Count(ts, 'T'), new Count(gs, 'G'), new Count(cs, 'C')};
            Arrays.sort(counts);
            for (int j=0; j<4; j++) {
                sb.append(counts[j].c);
            }
            sb.append("\n");
        }
        System.out.print(sb);
    }
}
class Count implements Comparable<Count> {
    int value;
    char c;
    public Count(int valuee, char cc) {
        value = valuee;
        c = cc;
    }

    public int compareTo(Count c2) {
        if (value == c2.value) {
            if (c == c2.c) {
                return 0;
            }
            if (c == 'A' || c2.c == 'C') {
                return -1;
            }
            if (c == 'C' || c2.c == 'A') {
                return 1;
            }
            if (c == 'T' || c2.c == 'G') {
                return -1;
            }
            return 1;
        }
        return c2.value - value;
    }
    public String toString() {
        return String.format("%d%s", value, c);
    }
}
