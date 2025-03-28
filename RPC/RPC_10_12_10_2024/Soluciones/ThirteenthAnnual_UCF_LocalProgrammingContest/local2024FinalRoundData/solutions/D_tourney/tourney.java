// Arup Guha
// 8/14/2024
// Solution to 2024 UCF Locals Problem: Fixing the Tournament

import java.util.*;

public class tourney {

	public static void main(String[] args) {
	
		Scanner stdin = new Scanner(System.in);
		int numR = stdin.nextInt();
		int rank = stdin.nextInt();
		
		// This is your rank from the end. Worst team gets 1 here.
		int fromEnd = (1<<numR) - rank + 1;
		
		// Everyone makes it into round 1!
		int res = 1;
		
		// Divide total teams by 2 and if you're still alive, you make it to 
		// the next round.
		while (fromEnd > 1) {
			res++;
			fromEnd = fromEnd/2;
		}

		// Ta da! - little tricky, you can't make it past the last round!
		System.out.println(Math.min(res, numR));
	}
}
		