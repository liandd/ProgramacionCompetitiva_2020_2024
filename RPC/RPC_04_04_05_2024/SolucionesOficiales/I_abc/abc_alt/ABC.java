// Arup Guha
// 8/16/2023
// Alternate Solution to 2023 UCF Local Qualifying Round Problem: Know your ABCs

import java.util.*;

public class ABC {

	final public static long MOD = 1000000007;

	public static long[][][][] dp;

	public static void main(String[] args) {
	
		Scanner stdin = new Scanner(System.in);
		int a = stdin.nextInt();
		int b = stdin.nextInt();
		int c = stdin.nextInt();
		 
		// Set up memo table.
		dp = new long[4][a+1][b+1][c+1];
		for (int i=0; i<4; i++)
			for(int j=0; j<=a; j++)
				for (int k=0; k<=b; k++)
					Arrays.fill(dp[i][j][k], -1);
		
		// 3 means none of a, b or c came prior.
		long res = go(3,a,b,c);
		System.out.println(res);
	}
	
	public static long go(int s, int a, int b, int c) {
		
		// Base cases...
		if (dp[s][a][b][c] != -1) return dp[s][a][b][c];
		if (a == 0 && b == 0 && c == 0) return 1;
		if (a == 0 && b == 0 && c > 1) return 0;
		if (a == 0 && b > 1 && c == 0) return 0;
		if (a > 1 && b == 0 && c == 0) return 0;
		
		// Try all three letters next, as long as they are valid.
		long res = 0;
		if (s!=0 && a>0) res += go(0, a-1, b, c);
		if (s!=1 && b>0) res += go(1, a, b-1, c);
		if (s!=2 && c>0) res += go(2, a, b, c-1);
		res %= MOD;
		
		// Store and return answer.
		return dp[s][a][b][c] = res;
	}
}