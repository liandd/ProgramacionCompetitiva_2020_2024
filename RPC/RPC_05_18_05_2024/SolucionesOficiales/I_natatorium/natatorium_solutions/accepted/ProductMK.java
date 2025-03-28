import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.HashSet;
import java.util.Set;
import java.util.StringTokenizer;


/**
 * ICPC - CTU Open Contest 2023
 * Sample Solution: ?
 * 
 * @author Martin Kacer
 */
public class ProductMK {
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
	long nextLong() {
		return Long.parseLong(nextToken());
	}
	public static void main(String[] args) {
		new ProductMK().run();
	}
	
	void run() {
		Set<Long> pos = new HashSet<>();
		long c = nextLong();
		int m = (int) nextLong();
		while (m-->0) {
			long p = nextLong(), q = c / p;
			pos.add(p);
			if (q * (long)p != c) continue;
			if (pos.contains(q)) {
				System.out.println(Math.min(p,  q) + " " + Math.max(p, q));
				return;
			}
		}
	}
}
