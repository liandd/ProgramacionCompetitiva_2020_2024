// Arup Guha
// 8/26/2024
// Solution to 2024 UCF Locals Problem: Teamwork

import java.util.*;

public class teamwork {

	// For Hungarian...
	public static int[] rowMatchesWith;

	// Original data is stored here.
	public static int[][] mat;
	public static int nStud;
	public static int nProb;
	public static int limit;
	
	public static void main(String[] args) {
	
		// Read basic data.
		Scanner stdin = new Scanner(System.in);
		nStud = stdin.nextInt();
		nProb = stdin.nextInt();
		limit = stdin.nextInt();
		
		// Hungarian matching matrix. Just stores original values.
		mat = new int[nProb][nStud];
		
		// Read in times. If you can't do a problem, we make it really big.
		for (int j=0; j<nStud; j++) {
			for (int i=0; i<nProb; i++) { 
				mat[i][j] = stdin.nextInt();
				if (mat[i][j] == 0)
					mat[i][j] = 1000000;
			}
		}
		
		// Limits for binary search.
		int low = 0, high = Math.min(nProb, nStud);
		
		// Run a binary search.
		while (low < high) {
			
			// # of problems we are trying to solve.
			int mid = (low+high+1)/2;
			
			// We can do it in time, answer is atleast mid.
			if (canDo(mid))
				low = mid;
			
			// We can't do mid, so mid-1 is most we could possibly do.
			else
				high = mid-1;
		}
		
		// Ta da!
		System.out.println(low);
	}
	
	// Returns true iff we can solve solved # of problems in time.
	public static boolean canDo(int solved) {
		
		// These are the unsolved problems.
		int unsolved = nProb - solved;
		
		// So we create some perfect students, who will solve the unsolved problems in 0 time.
		int[][] m = new int[nProb][nStud+unsolved];
		
		// Just copy the original values, and the 0s are for those perfect students.
		for (int j=0; j<nStud; j++) 
			for (int i=0; i<nProb; i++) 
				m[i][j] = mat[i][j];
				
		// Run Hungarian; if total cost is less than limit, we can solve solved # of problems.
		int mincost = hungarian(m);
		return mincost <= limit;
	}
	
	/*** UCF Hackpack for Hungarian circa Sage, Kamino era. ***/
	public static int hungarian(int[][] a) {

		int n=a.length, m=a[0].length; if (n>m) throw null;
		int[] u=new int[n], v=new int[m+1]; //edge (i->j) >= u[i]+v[j]
		int[] p=new int[m+1]; //p[j] = left match for right node j
		Arrays.fill(p, -1);

		for (int i=0; i<n; i++) {//find alternating path for node i
			int j0=m; p[j0]=i;
			int[] dist=new int[m+1], from=new int[m+1];
			boolean[] seen=new boolean[m+1];
			Arrays.fill(dist, Integer.MAX_VALUE);
			Arrays.fill(from, -1);

			while (p[j0]!=-1) {

				seen[j0]=true; int i0=p[j0], delta=Integer.MAX_VALUE, j1=-1;
				for (int j=0; j<m; j++) {//consider edges i0 -> everything
					if (seen[j]) continue;
					int candDist=a[i0][j]-u[i0]-v[j];
					if (candDist<dist[j]) {dist[j]=candDist; from[j]=j0;}
					if (dist[j]<delta) {delta=dist[j]; j1=j;}
				}
				
				//it costs at least delta to get somewhere else,
				//subtract that from all distances and add cost to u, v, arrays
				//from all done -> not done edges
				for (int j=0; j<=m; j++) {
					if (seen[j]) {u[p[j]]+=delta; v[j]-=delta;}
					else dist[j]-=delta;
				}

				j0=j1;
			}
			
			//flip alternating path
			while (j0!=m) { int j1=from[j0]; p[j0]=p[j1]; j0=j1; }
		}
		
		//sum of deltas is stored at v[m] coincidentally
		int ans=-v[m];
		rowMatchesWith=new int[n];
		for (int j=0; j<m; j++) 
			if (p[j]!=-1) rowMatchesWith[p[j]]=j;

		return ans;
	}

}
