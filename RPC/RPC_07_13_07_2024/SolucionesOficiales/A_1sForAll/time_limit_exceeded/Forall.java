import java.util.Scanner;

public class Forall {

	public static void main(String[] args) {

		Scanner in = new Scanner(System.in);
		int n = in.nextInt();
		System.out.println(doit(n));
	}
	
	public static int doit(int n)
	{
		if (n <= 5)
			return n;
		else {
			int best = doit(1) + doit(n-1);
			for(int i=2; i<=n/2; i++) {
				int cost = doit(i) + doit(n-i);
				if (cost < best)
					best = cost;
			}
			for(int i=2; i<= Math.sqrt(n); i++) {
				if (n%i == 0) {
					int cost = doit(i) + doit(n/i);
					if (cost < best)
						best = cost;
				}
			}
			String s = n+"";
			for(int i=1; i<s.length(); i++) {
				if (s.charAt(i) != '0') {
					int n1 = Integer.parseInt(s.substring(0,i));
					int n2 = Integer.parseInt(s.substring(i));
					int cost = doit(n1) + doit(n2);
					if (cost < best)
						best = cost;
				}
			}
			return best;
		}
	}
}