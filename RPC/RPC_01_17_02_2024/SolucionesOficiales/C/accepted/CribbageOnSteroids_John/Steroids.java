import java.util.Scanner;

public class Steroids {

	public static final int MAXCARDS = 100;
	public static long[][] table = new long[16][MAXCARDS];
	public static long[] counts = new long[15];
	public static int[] values = {0,1,2,3,4,5,6,7,8,9,10,10,10,10};

	public static void main(String[] args) {

		Scanner in = new Scanner(System.in);

		int n = in.nextInt();
		for(int i=0; i<n; i++) {
			char ch = in.next().charAt(0);
			switch (ch) {
			case 'A' : counts[1]++; break;
			case 'T' : counts[10]++; break;
			case 'J' : counts[11]++; break;
			case 'Q' : counts[12]++; break;
			case 'K' : counts[13]++; break;
			default : counts[ch-'0']++;		
			}
		}
		long pairPoints = 0;
		for(int i=1; i<=13; i++) {
			pairPoints += counts[i]*(counts[i]-1);
		}
//		System.out.println(pairPoints);

		long runPoints = 0;
		int runLength = 0;
		long currPoints = 0;
		for(int i=1; i<=14; i++) {
			if (counts[i] == 0) {
				if (runLength >=3)
					runPoints += currPoints*runLength;
				currPoints = 0;
				runLength = 0;
			}
			else {
				runLength++;
				if (runLength == 1)
					currPoints = counts[i];
				else
					currPoints *= counts[i];
			}
		}
//		System.out.println(runPoints);
		
		table[0][0] = 1;
		int j=1;
		while (counts[j] == 0)
			j++;
		table[values[j]][0] = 1;
		int numVal = 1;
		for(int i=1; i<n-1; i++) {
			if (numVal == counts[j]) {
				j++;
				while (counts[j] == 0)
					j++;
				numVal = 0;
			}
			numVal++;
			for(int r=0; r<=15; r++)
				table[r][i] = table[r][i-1];
			for(int r=values[j]; r<=15; r++)
				table[r][i] += table[r-values[j]][i-1];
		}
		if (numVal == counts[j]) {
			j++;
			while (counts[j] == 0)
				j++;
		}
		long fifteenPoints = (table[15][n-2] + table[15-values[j]][n-2])*2;
/*
		for(int r=15; r>=0; r--) {
			for(int c=0; c<n-1; c++) {
				System.out.printf("%3d", table[r][c]);
			}
			if (r == 15)
				System.out.printf("%3d", fifteenPoints/2);
			System.out.println();
		}
/**/
//		System.out.println(fifteenPoints);
		long totalPoints = pairPoints+runPoints+fifteenPoints;
		System.out.println(totalPoints);
		
	}

}
