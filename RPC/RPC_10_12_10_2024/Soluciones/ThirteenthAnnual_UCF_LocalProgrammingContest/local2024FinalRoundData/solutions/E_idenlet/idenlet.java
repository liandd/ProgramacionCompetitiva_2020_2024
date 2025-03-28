// Arup Guha
// 8/16/2024
// Solution to 2024 UCF Locals Problem: Identical Letters.

import java.util.*;

public class idenlet {

	public static char[] s;
	public static int skip;

	public static void main(String[] args) {
	
		Scanner stdin = new Scanner(System.in);
		s = stdin.next().toCharArray();
		skip = stdin.nextInt();
		
		// Create a list for each letter.
		ArrayList<Integer>[] idx = new ArrayList[26];
		for (int i=0; i<26; i++)
			idx[i] = new ArrayList<Integer>();
			
		// Store, in order, for each letter, the indexes it's in.
		for (int i=0; i<s.length; i++)
			idx[s[i]-'a'].add(i);
			
		// Get the best answer for each letter and take the max.
		int res = 0;
		for (int i=0; i<26; i++)
			res = Math.max(res, best(idx[i]));
			
		// Ta da!
		System.out.println(res);
	}
	
	// Returns the length of the most number of letters in a block
	// with at most skip other letters.
	public static int best(ArrayList<Integer> idxList) {
	
		// Get this out of the way.
		if (idxList.size() == 0) return 0;
		
		int low = 0, high = 0, res = 1;
		while (high < idxList.size()) {
		
			// A range of indexes with skip or fewer other numbers, see if this helps.
			if (high < idxList.size() && idxList.get(high) - idxList.get(low) <= high - low + skip) {
				res = Math.max(res, high-low+1);
				high++;
			}
			
			// We must move our low pointer up.
			else
				low++;
		}
		
		// Ta da!
		return res;
	}
}