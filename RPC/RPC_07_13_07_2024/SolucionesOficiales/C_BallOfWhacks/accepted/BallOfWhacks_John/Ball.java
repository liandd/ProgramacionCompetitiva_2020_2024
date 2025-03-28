import java.util.HashMap;
import java.util.Map;
import java.util.Scanner;

public class Ball {

	public static int [][] rotations1 = new int[31][];	// rotations[i][j] = where j goes if 1 goes to i
	public static int [][] rotations2 = new int[31][];	// rotations[i][j] = where j goes if 1 goes to i
	public static int [] sizes;
	public static int [][] parts;

	public static void main(String [] args)
	{
		Scanner in = new Scanner(System.in);
		int np = 3;
		sizes = new int[np];
		parts = new int[np][];

		buildRotations();
		int sum = 0;
		for(int p=0; p<np; p++) {
			sizes[p] = in.nextInt();
			sum += sizes[p];
			parts[p] = new int[sizes[p]];
			for(int i=0; i<sizes[p]; i++) {
				parts[p][i] = in.nextInt();
			}
		}
		boolean [] free = new boolean[31];
		for(int i=1; i<=30; i++)
			free[i] = true;
		for(int i=0; i<sizes[0]; i++)
			free[parts[0][i]] = false;
		if (sum != 30)
			System.out.println("No");
		else if (check(1, np, free))
			System.out.println("Yes");
		else
			System.out.println("No");
	}
	
	public static boolean check(int ip, int np, boolean [] free)
	{
		if (ip == np)
			return true;
		for(int i=1; i<=30; i++) {
			if (!free[i])
				continue;
			if (okToTransform(ip, rotations1[i], free)) {
				for(int j=0; j<sizes[ip]; j++) {
					free[rotations1[i][parts[ip][j]]] = false;
				}
				if (check(ip+1, np, free))
					return true;
				for(int j=0; j<sizes[ip]; j++) {
					free[rotations1[i][parts[ip][j]]] = true;
				}
			}
			if (okToTransform(ip, rotations2[i], free)) {
				for(int j=0; j<sizes[ip]; j++) {
					free[rotations2[i][parts[ip][j]]] = false;
				}
				if (check(ip+1, np, free))
					return true;
				for(int j=0; j<sizes[ip]; j++) {
					free[rotations2[i][parts[ip][j]]] = true;
				}
			}
		}
		
		return false;
	}

	public static boolean okToTransform(int ip, int[] transform, boolean[] free)
	/*
	 * for part ip see if it can be transformed to all free pieces using transform
	 */
	{
		for(int i=0; i<sizes[ip]; i++) {
			if (!free[transform[parts[ip][i]]])
				return false;
		}
		return true;
	}
	public static void buildRotations()
	/*
	 * initially set up so that tmp[i][j] = where j goes if i goes to 1
	 * then change to rotations[i][j] = where j goes if 1 goes to i
	 */
	{
		int [][] tmp1 = new int[31][];
		int [][] tmp2 = new int[31][31];
		int [] row1 = {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30};
		int [] row2 = {0,5,1,2,3,4,10,6,7,8,9,19,20,11,12,13,14,15,16,17,18,25,21,22,23,24,30,26,27,28,29};
		tmp1[1] = row1;
		tmp1[2] = row2;
		for(int r=3; r<=5; r++) {
			tmp1[r] = new int[31];
			for(int c=1; c<=30; c++)
				tmp1[r][c] = tmp1[r-1][tmp1[2][c]];	// rotate r->2, 2->1
		}
		int [] row6 = { 0, 2, 6,11,12, 7, 1,20,21,13, 3,10,19,25,26,27,22,14, 8, 4, 5,18,30,28,15, 9,17,24,29,23,16};
		tmp1[6] = row6;
		for(int r=7; r<=10; r++) {
			tmp1[r] = new int[31];
			for(int c=1; c<=30; c++)
				tmp1[r][c] = tmp1[6][tmp1[r-5][c]];	// rotate r->6, 6->1
		}
		int [] row11 = { 0, 9, 4, 8,15,16, 5, 3,14,23,17, 1, 2, 7,13,22,28,29,24,18,10, 6,12,27,30,19,20,11,21,26,25};
		int [] row12 = { 0, 8, 3, 7,13,14, 4, 2,12,22,15, 5, 1, 6,11,21,27,28,23,16, 9,10,20,26,29,17,18,19,25,30,24};
		tmp1[11] = row11;
		tmp1[12] = row12;
		for(int r=13; r<=20; r+=2) {
			tmp1[r] = new int[31];
			tmp1[r+1] = new int[31];
			for(int c=1; c<=30; c++) {
				tmp1[r][c] = tmp1[11][tmp1[(r-9)/2][c]];	    // rotate r->11, 11->1
				tmp1[r+1][c] = tmp1[12][tmp1[(r-9)/2][c]];	// rotate r->12, 12->1
			}
		}
		int [] row21 = { 0,13,12,21,27,22, 7,11,26,28,14, 2, 6,20,25,30,29,23,15, 8, 3, 1,19,24,16, 4, 5,10,18,17, 9};
		tmp1[21] = row21;
		for(int r=22; r<=25; r++) {
			tmp1[r] = new int[31];
			for(int c=1; c<=30; c++)
				tmp1[r][c] = tmp1[21][tmp1[r-20][c]];	// rotate r->21, 21->1
		}
		int [] row26 = { 0,15,14,22,28,23, 8,13,27,29,16, 3, 7,12,21,26,30,24,17, 9, 4, 2,11,25,18, 5, 1, 6,20,19,10};
		tmp1[26] = row26;
		for(int r=27; r<=30; r++) {
			tmp1[r] = new int[31];
			for(int c=1; c<=30; c++)
				tmp1[r][c] = tmp1[26][tmp1[r-25][c]];	// rotate r->26, 26->1
		}
		/*
		for(int r=1; r<=30; r++) {
			System.out.printf("%2d:", r);
			for(int c=1; c<=30; c++) {
				System.out.printf("%3d", tmp1[r][c]);
			}
			System.out.println();
		}
/**/		
		int [] invert = { 0, 1,10,19,20, 6, 5,18,25,11, 2, 9,17,24,30,26,21,12, 7, 3, 4,16,29,27,13, 8,15,23,28,22,14};
		for(int r=1; r<=30; r++)
			for(int c=1; c<=30; c++)
				tmp2[r][c] = invert[tmp1[r][c]];
		/* 
		for(int r=1; r<=30; r++) {
			System.out.printf("%2d:", r);
			for(int c=1; c<=30; c++) {
				System.out.printf("%3d", tmp2[r][c]);
			}
			System.out.println();
		}
/**/		
		for(int i=1; i<=30; i++) {
			int g = tmp1[i][1];
			if (rotations1[g] == null)
				rotations1[g] = tmp1[i];
			else
				rotations2[g] = tmp1[i];
		}
		for(int i=1; i<=30; i++) {
			int g = tmp2[i][1];
			if (rotations1[g] == null)
				rotations1[g] = tmp2[i];
			else
				rotations2[g] = tmp2[i];
		}
		/*		
		int [] check = {1,6,10,20,25};
		int moveto = 11;
		System.out.println("check");
		for(int i=0; i<check.length; i++)
			System.out.println(check[i] + "->" + rotations1[moveto][check[i]] + " or " + rotations2[moveto][check[i]]);
/**/	
	}
}









