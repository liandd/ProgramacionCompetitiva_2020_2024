// Arup Guha
// 8/11/2023
// Solution to 2023 UCF Local Qualifying Round Problem: Brightline

import java.util.*;

public class Brightline {

	public static void main(String[] args) {
	
		Scanner stdin = new Scanner(System.in);
		int n = stdin.nextInt();
		int m = stdin.nextInt();
		
		// Add edges.
		ArrayList<edge> eList = new ArrayList<edge>();
		for (int i=0; i<m; i++) {
			int u = stdin.nextInt()-1;
			int v = stdin.nextInt()-1;
			
			// We set our multiplier to 1 if positive, -1 if negative.
			int mult = stdin.next().equals("b") ? 1 : -1;
			int w = stdin.nextInt();
			
			// Ready to add edge.
			eList.add(new edge(u,v,mult*w));
		}
		
		// Sufficient for our bounds.
		int[] res = new int[n];
		Arrays.fill(res, 1000000000);
		res[0] = 0;
		
		// Relax all the edges n-1 times! (Bellman-Ford)
		for (int i=0; i<n-1; i++)
			for (edge e: eList)
				if (res[e.u] + e.w < res[e.v])
					res[e.v] = res[e.u] + e.w;
					
		// Output all the places we could be younger.
		for (int i=1; i<n; i++)
			if (res[i] < 0)
				System.out.println(i+1);
	}
}

class edge {

	public int u;
	public int v;
	public int w;
	
	public edge(int from, int to, int myw) {
		u = from;
		v = to;
		w = myw;
	}
}