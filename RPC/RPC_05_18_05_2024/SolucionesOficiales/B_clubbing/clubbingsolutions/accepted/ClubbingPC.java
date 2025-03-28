import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.List;
import java.util.StringTokenizer;

/**
 * ICPC - CTU Open Contest 2023
 * Sample Solution: Clubbing
 */

public class ClubbingPC {
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
    new ClubbingPC().run();
  }
  
  static final int MAX = 17;

  void run() {
    int d = nextInt();
    // isClub[i]: Whether the set encoded in bitmap i contains some full club.
    boolean[] isClub = new boolean[1 << MAX];
    for (int i = 0; i < d; ++i) {
      String cl = nextToken();
      int bitmap = 0;
      for (char c : cl.toCharArray()) bitmap |= (1 << (c - 'a'));
      isClub[bitmap] = true;
    }
    // Calculate isClub ... expand bitmaps of clubs.
    for (int i = 0; i < (1 << MAX); ++i) if (isClub[i]) {
      for (int j = 0; j < MAX; ++j) {
        isClub[i | (1 << j)] = true;
      }
    }
    String seqStr = nextToken();
    List<Integer> seq = new ArrayList<>();
    for (char c : seqStr.toCharArray()) seq.add(c - 'a');
    int len = seq.size();
    
    int[] cnt = new int[MAX];
    int bitmap = 0;
    long result = 0;
    int b = 0, e = 0; // Looking at substring starting in b, ending in e - 1.
    while(e < len) {
      // Push end until a full club is covered.
      while (!isClub[bitmap] && e < len) {
        int vale = seq.get(e);
        cnt[vale]++;
        if (cnt[vale] == 1) bitmap += (1 << vale);
        e++;
      }
      // Push beginning as long as a full club is covered.
      while (isClub[bitmap]) {
        result += len - e + 1;
        int valb = seq.get(b);
        cnt[valb]--;
        if(cnt[valb] == 0) bitmap -= (1 << valb);
        b++;
      }
    }

    System.out.println(result);
  }
}
