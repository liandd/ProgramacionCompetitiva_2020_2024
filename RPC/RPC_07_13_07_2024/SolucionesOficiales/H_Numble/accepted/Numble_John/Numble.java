import java.util.Scanner;

public class Numble {

	public static final int MAXSIZE = 20;

	public static char[][] board = new char[MAXSIZE+2][MAXSIZE+2];
	public static char[][] rboard = new char[MAXSIZE+2][MAXSIZE+2];
	public static int[][] vals = new int[MAXSIZE+2][MAXSIZE+2];
	public static int rows, cols;
	public static int[] tiles = new int[MAXSIZE];
	public static int numTiles;
	public static int bestScore;
	public static Scanner in = new Scanner(System.in);

	public static void main(String[] args) {

		rows = in.nextInt();
		cols = in.nextInt();
		for(int i=0; i<MAXSIZE+2; i++)
			for(int j=0; j<MAXSIZE+2; j++) {
				board[i][j] = '-';
				rboard[i][j] = '-';
				vals[i][j] = 0;
			}
		for(int i=1; i<=rows; i++) {
			for(int j=1; j<=cols; j++) {
				String s = in.next();
				board[i][j] = s.charAt(0);
				rboard[j][i] = board[i][j];
			}
		}
		numTiles = in.nextInt();
		tiles[0] = in.nextInt();
		for(int i=1; i<numTiles; i++) {
			int val = in.nextInt();
			int j=i;
			while (j > 0 && tiles[j-1] > val) {
				tiles[j] = tiles[j-1];
				j--;
			}
			tiles[j] = val;
		}

		processBoard(rows, cols);

		board = rboard;
		int tmp = rows;
		rows = cols;
		cols = tmp;
		processBoard(rows, cols);

		System.out.println(bestScore);
	}

	public static void processBoard(int rows, int cols)
	{
		for(int i=0; i<MAXSIZE+2; i++)
			for(int j=0; j<MAXSIZE+2; j++) {
				vals[i][j] = 0;
			}
		for(int i=1; i<=rows; i++) {
			for(int j=1; j<=cols; j++) {
				if (Character.isDigit(board[i][j]))
					vals[i][j] = board[i][j] - '0';
			}
		}
		for(int r=1; r<=rows; r++) {
			for(int c=1; c<=cols; c++)
				processRow(r, c, 0, false);		
		}
		for(int i=0; i<numTiles/2; i++) {
			int tmp = tiles[i];
			tiles[i] = tiles[numTiles-i-1];
			tiles[numTiles-i-1] = tmp;
		}
		for(int r=1; r<=rows; r++) {
			for(int c=1; c<=cols; c++)
				processRow(r, c, 0, false);		
		}
	}

	public static void processRow(int r, int c, int index, boolean isConnected)
	{
		//		printVals();
		//		String s = in.nextLine();

		if (c > cols || index == numTiles) {
			return;
		}
		if (Character.isDigit(board[r][c])) {
			processRow(r, c+1, index, true);
		}
		else {
			if (Character.isDigit(board[r-1][c]) || Character.isDigit(board[r+1][c]))
				isConnected = true;

			for(int i = index; i<numTiles; i++) {
				vals[r][c] = tiles[i];
//System.out.println("Placing " + tiles[i] + " at location (" + r + "," + c);
				if (isConnected) {
					evaluateBoard();
				}
				processRow(r, c+1, i+1, isConnected);
			}
			vals[r][c] = 0;
		}
	}

	public static void evaluateBoard()
	{
		boolean debug = false;
		if (debug) {
			System.out.println("evalBoard");
			printVals();
		}
		int total = 0;
		for(int c=1; c<=cols; c++) {
			if (skipColumn(c))
				continue;
			int runningSum = 0;
			int mult = 1;
			int length = 0;
			boolean increasing = false, decreasing = false;
			boolean newseq = false;
			for(int r=1; r<=rows+1; r++) {
				if (vals[r][c] == 0) {
					if (length > 1 && newseq) {
						if ((runningSum*mult)%3 != 0)
							return;
						total += runningSum*mult;
					}
					runningSum = 0;
					mult = 1;
					length = 0;
					newseq = false;
					increasing = decreasing = false;
				}
				else {
					length++;
					if (length >= 2) {
						if (increasing && vals[r][c] < vals[r-1][c])
							return;
						if (decreasing && vals[r][c] > vals[r-1][c])
							return;
						increasing = increasing || (vals[r][c] > vals[r-1][c]);
						decreasing = decreasing || (vals[r][c] < vals[r-1][c]);
					}
					if (!Character.isDigit(board[r][c]))
						newseq = true;
					int numMult = 1;
					if (board[r][c] == 'D')
						mult *= 2;
					else if (board[r][c] == 'T')
						mult *= 3;
					else if (board[r][c] == 'd')
						numMult = 2;
					else if (board[r][c] == 't')
						numMult = 3;
					runningSum += vals[r][c]*numMult;
				}
			}
			if (debug)
				System.out.println("total after col " + c + ": " + total);
		}
		for(int r=1; r<=rows; r++) {
			if (skipRow(r))
				continue;
			int runningSum = 0;
			int mult = 1;
			int length = 0;
			boolean increasing = false, decreasing = false;
			boolean newseq = false;
			for(int c=1; c<=cols+1; c++) {
				if (vals[r][c] == 0) {
					if (length > 1 && newseq) {
						if ((runningSum*mult)%3 != 0)
							return;
						total += runningSum*mult;
					}
					runningSum = 0;
					mult = 1;
					length = 0;
					newseq = false;
					increasing = decreasing = false;
				}
				else {
					length++;
					if (length >= 2) {
						if (increasing && vals[r][c] < vals[r][c-1])
							return;
						if (decreasing && vals[r][c] > vals[r][c-1])
							return;
						increasing = increasing || (vals[r][c] > vals[r][c-1]);
						decreasing = decreasing || (vals[r][c] < vals[r][c-1]);
					}
					if (!Character.isDigit(board[r][c]))
						newseq = true;
					int numMult = 1;
					if (board[r][c] == 'D')
						mult *= 2;
					else if (board[r][c] == 'T')
						mult *= 3;
					else if (board[r][c] == 'd')
						numMult = 2;
					else if (board[r][c] == 't')
						numMult = 3;
					runningSum += vals[r][c]*numMult;
				}
			}
			if (debug)
				System.out.println("total after row " + r + ": " + total);
		}
		if (total > bestScore) {
			bestScore = total;
			if (debug) {
				System.out.println("new best score = " + bestScore);
				printVals();
			}
		}
	}

	public static boolean skipColumn(int c)
	{
		for(int r=1; r<=rows; r++) {
			if (!Character.isDigit(board[r][c]) && vals[r][c] != 0)
				return false;
		}
		return true;
	}

	public static boolean skipRow(int r)
	{
		for(int c=1; c<=cols; c++) {
			if (!Character.isDigit(board[r][c]) && vals[r][c] != 0)
				return false;
		}
		return true;
	}

	public static void printVals()
	{
		for(int r=1; r<=rows; r++) {
			for(int c=1; c<=cols; c++) {
				if (vals[r][c] == 0)
					System.out.print("-");
				else
					System.out.print(vals[r][c]);
			}
			System.out.println();
		}
	}
}
