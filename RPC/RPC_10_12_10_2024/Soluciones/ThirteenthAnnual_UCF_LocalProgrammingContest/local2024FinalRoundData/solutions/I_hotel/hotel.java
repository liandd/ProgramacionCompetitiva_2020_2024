// Arup Guha
// 8/14/2024
// Solution to 2024 UCF Locals Problem: Hotel Rooms

import java.util.*;
import java.io.*;

public class hotel {

	public static void main(String[] args) throws Exception {
	
		BufferedReader stdin = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer tok = new StringTokenizer(stdin.readLine());
		int n = Integer.parseInt(tok.nextToken());
		int numOps = Integer.parseInt(tok.nextToken());
		
		// Build answer here.
		StringBuffer sb = new StringBuffer();
		
		// Stores hotel contents.
		bit ramada = new bit(n);
		
		// Process operations.
		for (int i=0; i<numOps; i++) {
			
			tok = new StringTokenizer(stdin.readLine());
			char cmd = tok.nextToken().charAt(0);
			
			// Reserve a new room.
			if (cmd == 'R') {
				int room = Integer.parseInt(tok.nextToken());
				ramada.add(room, 1);
			}
			
			// Query.
			else {
				int low = Integer.parseInt(tok.nextToken());
				int high = Integer.parseInt(tok.nextToken());
				
				// My bit stores taken rooms, so we would just subtract the taken
				// rooms from the total number of rooms in the range.
				sb.append((high - low + 1 - ramada.rangeSum(low,high))+"\n");
			}
		}
		
		// Ta da!
		System.out.print(sb);
	}
}

class bit {

	public int n;
	public int[] sum;
	
	public bit(int myn) {
	
		// Set size.
		n = 1;
		while (n < myn+1) n = (n<<1);
		
		// Allocate array.
		sum = new int[n];
	}
	
	// Add val to index idx.
	public void add(int idx, int val) {
		while (idx < n) {
			sum[idx] += val;
			idx += (idx&(-idx));
		}
	}
	
	// Returns the sum of arr[1]..arr[top];
	public int query(int top) {
		int res = 0;
		while (top > 0) {
			res += sum[top];
			top -= (top&(-top));
		}
		return res;
	}
	
	// Returns the sum arr[low]..arr[high]
	public int rangeSum(int low, int high) {
		return query(high) - query(low-1);
	}
}