import java.util.Scanner;

public class Musical {

	public static void main(String[] args) {

		int [] times;
		boolean [][][] table;
		Scanner in = new Scanner(System.in);
		int size, n;

		size = in.nextInt();
		n = in.nextInt();
		times = new int[n+1];
		for(int i=1; i<=n; i++)
			times[i] = in.nextInt();

		table = new boolean[n+1][size+1][size+1];
		table[0][size][size] = true;
		for(int i=1; i<=n; i++) {
			for(int j=0; j<=size; j++) {
				for(int k=0; k<=size; k++) {
					table[i][j][k] = table[i-1][j][k];
					if (j + times[i] > 0 && j + times[i] <= size && table[i-1][j+times[i]][k]) // j+times[i]>0 checks for overflow
						table[i][j][k] = true;
					if (k + times[i] > 0 && k + times[i] <= size && table[i-1][j][k+times[i]]) 
						table[i][j][k] = true;;
				}
			}
/*
			System.out.println("i = " + i);
			for(int j=0; j<=size; j++) {
				for(int k=0; k<=size; k++) {
					int val = table[i][j][k] ? 1 : 0;
					System.out.print(val + " ");
				}
				System.out.println();
			}
/**/
		}
										// search diagonals of last slice of table for minimal empty space
		boolean found = false;
		int cd1 = 0, cd2 = 0;
		for(int empty=0; empty<=2*size; empty++) {		// empty = remaining minutes not used on two CDs combined
			for(int i=Math.max(0, empty-size); i<=size; i++) {
				int j=empty-i;
				if (j < i)
					break;
				if (table[n][i][j]) {
					found = true;
					cd1 = size-i;
					cd2 = size-j;
				}
			}
			if (found)
				break;
		}
		System.out.println(cd1 + " " + cd2);

	}

}
