import java.util.ArrayList;
import java.util.Iterator;
import java.util.Scanner;

public class Tomb {

	public static final int MAXD = 50;
	public static final int MAXW = 50;
	public static final int EAST = 0;
	public static final int WEST = 1;

	public static int[][][][][] table = new int[MAXD][MAXD][MAXW][MAXW+1][2]; //table[r][c][i][j][e/w] = min length to get to j-th letter in i-th glyph at location (r,c) in grid either going east or west
	public static char[][] grid= new char[MAXD][MAXD];
	public static int rows, cols;
	public static String[] glyphs;
	public static int numG;

	public static void main(String [] args)
	{
		long start = System.nanoTime();
		Scanner in = new Scanner(System.in);
		rows = in.nextInt();
		cols = in.nextInt();
		numG = in.nextInt();
		glyphs = new String[numG];
		for(int r=0; r<rows; r++) {
			for(int c=0; c<cols; c++)
				grid[r][c] = in.next().charAt(0);
		}
		for(int i=0; i<numG; i++)
			glyphs[i] = in.next();
		int maxval = (rows*cols)+1;

		for(int c=0; c<cols; c++)
			for(int i=0; i<numG; i++) {
				if (grid[0][c] == glyphs[i].charAt(0))
					table[0][c][i][0][EAST] = table[0][c][i][0][WEST] = 1;
				else
					table[0][c][i][0][EAST] = table[0][c][i][0][WEST] = maxval;
				for(int j=1; j<glyphs[i].length(); j++)
					table[0][c][i][j][EAST] = table[0][c][i][j][WEST] = maxval;
			}
		for(int c=1; c<cols; c++) {				// handle East moves in first row
			int startNew = maxval;
			for(int i=0; i<numG; i++) {
				for(int j=1; j<=glyphs[i].length(); j++) {
					if (j == glyphs[i].length()) {
						if (table[0][c-1][i][j-1][EAST] + 1 < startNew)
							startNew = table[0][c-1][i][j-1][EAST] + 1;
					}
					else if (grid[0][c] == glyphs[i].charAt(j) && table[0][c-1][i][j-1][EAST]+1 < table[0][c][i][j][EAST])
						table[0][c][i][j][EAST] = table[0][c-1][i][j-1][EAST]+1;
				}	
			}
			if (startNew < maxval) {		// can start new glyph in this grid square
				for(int i=0; i<numG; i++)
					if (grid[0][c] == glyphs[i].charAt(0) && startNew < table[0][c][i][0][EAST])
						table[0][c][i][0][EAST] = startNew;
			}

		}
		for(int c=cols-2; c>=0; c--) {				// handle West moves in first row
			int startNew = maxval;
			for(int i=0; i<numG; i++) {
				for(int j=1; j<=glyphs[i].length(); j++) {
					if (j == glyphs[i].length()) {
						if (table[0][c+1][i][j-1][WEST] + 1 < startNew)
							startNew = table[0][c+1][i][j-1][WEST] + 1;
					}
					else if (grid[0][c] == glyphs[i].charAt(j) && table[0][c+1][i][j-1][WEST]+1 < table[0][c][i][j][WEST])
						table[0][c][i][j][WEST] = table[0][c+1][i][j-1][WEST]+1;
				}	
			}
			if (startNew < maxval) {		// can start new glyph in this grid square
				for(int i=0; i<numG; i++)
					if (grid[0][c] == glyphs[i].charAt(0) && startNew < table[0][c][i][0][WEST])
						table[0][c][i][0][WEST] = startNew;
			}
		}
		
		
		for(int r=1; r<rows; r++) {
			for(int c=0; c<cols; c++) {					// handle South moves (treated as moving East/West 0 squares)
				int startNew = maxval;
				for(int i=0; i<numG; i++) {
					table[r][c][i][0][EAST] = table[r][c][i][0][WEST] = maxval;
					for(int j=1; j<=glyphs[i].length(); j++) {
						table[r][c][i][j][EAST] = table[r][c][i][j][WEST] = maxval;
						if (table[r-1][c][i][j-1][EAST] == maxval && table[r-1][c][i][j-1][WEST] == maxval)
							continue;
						//if (r == 1) System.out.println("c, i, j = " + c + ","+i+","+j+", " + grid[r][c] + " " + glyphs[i].charAt(j) + " " + table[r-1][c][i][j-1]);
						if (j == glyphs[i].length()) {
							int val = Math.min(table[r-1][c][i][j-1][EAST], table[r-1][c][i][j-1][WEST]) +1;
							if (val < startNew)
								startNew = val;
						}						
						else {
							if (grid[r][c] == glyphs[i].charAt(j) && table[r-1][c][i][j-1][EAST]+1 < table[r][c][i][j][EAST])
								table[r][c][i][j][EAST] = table[r-1][c][i][j-1][EAST]+1;
							if (grid[r][c] == glyphs[i].charAt(j) && table[r-1][c][i][j-1][WEST]+1 < table[r][c][i][j][EAST])
								table[r][c][i][j][EAST] = table[r-1][c][i][j-1][WEST]+1;
						}
						table[r][c][i][j][WEST] = table[r][c][i][j][EAST];
					}
				}
				if (startNew < maxval) {		// can start new glyph in this grid square
					for(int i=0; i<numG; i++)
						if (grid[r][c] == glyphs[i].charAt(0))
							table[r][c][i][0][EAST] = table[r][c][i][0][WEST] = startNew;

				}
			}
/**/
			for(int c=1; c<cols; c++) {				// handle East moves
				int startNew = maxval;
				for(int i=0; i<numG; i++) {
					for(int j=1; j<=glyphs[i].length(); j++) {
						if (j == glyphs[i].length()) {
							if (table[r][c-1][i][j-1][EAST] + 1 < startNew)
								startNew = table[r][c-1][i][j-1][EAST] + 1;
						}
						else if (grid[r][c] == glyphs[i].charAt(j) && table[r][c-1][i][j-1][EAST]+1 < table[r][c][i][j][EAST])
							table[r][c][i][j][EAST] = table[r][c-1][i][j-1][EAST]+1;
					}	
				}
				if (startNew < maxval) {		// can start new glyph in this grid square
					for(int i=0; i<numG; i++)
						if (grid[r][c] == glyphs[i].charAt(0) && startNew < table[r][c][i][0][EAST])
							table[r][c][i][0][EAST] = startNew;
				}

			}
			for(int c=cols-2; c>=0; c--) {				// handle West moves
				int startNew = maxval;
				for(int i=0; i<numG; i++) {
					for(int j=1; j<=glyphs[i].length(); j++) {
						if (j == glyphs[i].length()) {
							if (table[r][c+1][i][j-1][WEST] + 1 < startNew)
								startNew = table[r][c+1][i][j-1][WEST] + 1;
						}
						else if (grid[r][c] == glyphs[i].charAt(j) && table[r][c+1][i][j-1][WEST]+1 < table[r][c][i][j][WEST])
							table[r][c][i][j][WEST] = table[r][c+1][i][j-1][WEST]+1;
					}	
				}
				if (startNew < maxval) {		// can start new glyph in this grid square
					for(int i=0; i<numG; i++)
						if (grid[r][c] == glyphs[i].charAt(0) && startNew < table[r][c][i][0][WEST])
							table[r][c][i][0][WEST] = startNew;
				}
			}
		}
/**/
		long end = System.nanoTime();
//		System.out.println((end-start)/1000000000.0);
/*
		for(int r=0; r<rows; r++)
			for(int c=0; c<cols; c++) {
				System.out.println(r + "," + c + " " + grid[r][c]);
				for(int i=0; i<numG; i++) {
					for(int j=0; j<glyphs[i].length(); j++)
						System.out.print(""+table[r][c][i][j][EAST]+glyphs[i].charAt(j) + " ");
					System.out.print(" ");
					for(int j=0; j<glyphs[i].length(); j++)
						System.out.print(""+table[r][c][i][j][WEST]+glyphs[i].charAt(j) + " ");
					System.out.print(" | ");
				}
				System.out.println();
			}
/**/
		int bestVal = maxval;
		for(int c=0; c<cols; c++) {
			for(int i=0; i<numG; i++) {
				if (table[rows-1][c][i][glyphs[i].length()-1][EAST] < bestVal)
					bestVal = table[rows-1][c][i][glyphs[i].length()-1][EAST];
				if (table[rows-1][c][i][glyphs[i].length()-1][WEST] < bestVal)
					bestVal = table[rows-1][c][i][glyphs[i].length()-1][WEST];
			}
		}
		if (bestVal == maxval)
			System.out.println("impossible");
		else
			System.out.println(bestVal);
		in.close();
	}
}