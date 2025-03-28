// Arup Guha
// 8/18/2024
// Solution to 2024 UCF Locals Problem: Speed Ups

import java.util.*;

public class speed {

	public static void main(String[] args) {
	
		Scanner stdin = new Scanner(System.in);
		int n = stdin.nextInt();
		int distance = stdin.nextInt();
		
		// Make array of boosts.
		boost[] help = new boost[n];
		for (int i=0; i<n; i++) {
			int x = stdin.nextInt();
			int m = stdin.nextInt();
			int t = stdin.nextInt();
			help[i] = new boost(x, m, t, i);
		}
		
		// These need to be in order.
		Arrays.sort(help);
		
		// dp[i] will store fastest time to get to boost i.
		int[] dp = new int[n];
		
		for (int i=0; i<n; i++) {
			
			// If we take no boosts, this is how long we would take to get here.
			dp[i] = help[i].x;
			
			// Try boost j as your last boost before getting to boost i.
			for (int j=0; j<i; j++) {
			
				// Not allowed to build off of a boost that shoots you past this point.
				if (help[j].xend > help[i].x) continue;
				
				// The time to boost j is dp[j]. Then we'll take the boost which lasts
				// for help[j].time seconds, which will put us as x coordinate help[j].end.
				// From there, we go 1 m/s to the start of boost i.
				dp[i] = Math.min(dp[i], dp[j] + help[j].time + help[i].x - help[j].xend);
			}
		}
		
		// The finish line is a little special (because a boost can go through it)
		// This means our answer here could be a double even though all the DP values are ints.
		
		// No boosts.
		double res = distance;
		
		// Try building off of each previous one.
		for (int i=0; i<n; i++) {
			
			// Boost ends before end of race, we use the same formula as the DP.
			if (help[i].xend <= distance)
				res = Math.min(res, dp[i] + help[i].time + distance - help[i].xend);
				
			// Here we finish the race on the boost so we calculate the distance from
			// the start of boost i to the end of the race and divide that by the speed
			// of the boost.
			else
				res =  Math.min(res, dp[i] + 1.0*(distance - help[i].x)/help[i].vel);
		}
		
		// Ta da!
		System.out.printf("%.9f\n",res);
	}
}

class boost implements Comparable<boost> {
	
	public int x;
	public int xend;
	public int vel;
	public int time;
	public int id;
	
	// Helpful to store the x value where the boost (speed up) ends.
	public boost(int myx, int myvel, int mytime, int myid) {
		x = myx;
		vel = myvel;
		time = mytime;
		xend = x + vel*time;
		id = myid;
	}

	// Sort by x then id.
	public int compareTo(boost other) {
		if (x != other.x) return x - other.x;
		return id - other.id;
	}
}