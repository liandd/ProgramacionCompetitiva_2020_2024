// Arup Guha
// 8/11/2023
// Solution to 2023 UCF Local Qualifying Round Problem: Know your ABCs

import java.util.*;

public class ABC {

	final public static long MOD = 1000000007;

	public static long[][][][] dp;

	public static void main(String[] args) {
	
		Scanner stdin = new Scanner(System.in);
		int a = stdin.nextInt();
		int b = stdin.nextInt();
		int c = stdin.nextInt();
		
		// Store results for one letter.
		dp = new long[3][a+1][b+1][c+1];
		dp[0][1][0][0] = 1;
		dp[1][0][1][0] = 1;
		dp[2][0][0][1] = 1;
		
		// First three loops are state of letter sums.
		for (int i=0; i<=a; i++) {
			for (int j=0; j<=b; j++) {
				for (int k=0; k<=c; k++) {
				
					// This is the last letter we are adding.
					for (int z=0; z<3; z++) {
					
						// We need one of these letters (designated by z) to form this state.
						if (z == 0 && i == 0) continue;
						if (z == 1 && j == 0) continue;
						if (z == 2 && k == 0) continue;
						
						// We can build off 2 possible previous cases.
						if (z == 0) dp[z][i][j][k] = (dp[z][i][j][k] + dp[1][i-1][j][k] + dp[2][i-1][j][k])%MOD;
						if (z == 1) dp[z][i][j][k] = (dp[z][i][j][k] + dp[0][i][j-1][k] + dp[2][i][j-1][k])%MOD;
						if (z == 2) dp[z][i][j][k] = (dp[z][i][j][k] + dp[0][i][j][k-1] + dp[1][i][j][k-1])%MOD;
					}
				}
			}
		}
		
		// Add and output.
		long res = 0;
		for (int i=0; i<3; i++) res += dp[i][a][b][c];
		res %= MOD;
		System.out.println(res);
	}
}