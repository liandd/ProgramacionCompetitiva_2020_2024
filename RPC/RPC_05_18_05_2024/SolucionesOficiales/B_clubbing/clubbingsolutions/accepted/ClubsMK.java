import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;


/**
 * ICPC - CTU Open Contest 2023
 * Sample Solution: Student Clubs
 * 
 * @author Martin Kacer
 */
public class ClubsMK {
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
		System.out.println(new ClubsMK().run());
	}
	
	static final int SIZE = 17, SIZE2 = 1<<SIZE;
	boolean[] vis = new boolean[SIZE2];
	int[] q = new int[SIZE2];
	int qh, qt;
	
	void enqueue(int m) {
		if (vis[m]) return;
		vis[m] = true;
		q[qt++] = m;
	}
	
	long run() {
		int n = nextInt();
		
		while (n-- > 0) {
			String s = nextToken();
			int m = 0;
			for (char c : s.toCharArray())
				m |= 1 << (c - 'a');
			enqueue(m);
		}
		while (qh < qt) {
			int m = q[qh++];
			for (int b = 1; b < SIZE2; b <<= 1) enqueue(m | b);
		}
		
		char[] txt = nextToken().toCharArray();
		int[] cnt = new int[SIZE];
		long res = 0;
		for (int tb = 0, te = 0, cm = 0; te < txt.length;) {
			while (!vis[cm] && te < txt.length) {
				int c = txt[te++]-'a';
				if (cnt[c]++ == 0) cm |= (1<<c);
			}
			while (vis[cm]) {
				res += txt.length - te + 1;
				int c = txt[tb++]-'a';
				if (--cnt[c] == 0) cm &= ~(1<<c);
			}
		}
		return res;
	}
}
