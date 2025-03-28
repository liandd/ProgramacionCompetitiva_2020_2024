import java.util.Scanner;

public class Files {

	public static final int MAXVALS = 100;

	public static int[] mapping = new int[MAXVALS+1];
	public static int[] finalOrder = new int[MAXVALS];

	public static void main(String [] args)
	{
		int p1, u1, p2, u2;
		Scanner in = new Scanner(System.in);

		p1 = in.nextInt();
		u1 = in.nextInt();
		for(int i=1; i<=p1+u1; i++) {
			int val = in.nextInt();
			mapping[val] = i;			// renumber initial list of files to 1,2,..., (p1+u1)
		}
		p2 = in.nextInt();
		u2 = in.nextInt();
		for(int i=0; i<p2+u2; i++) {
			int val = in.nextInt();
			finalOrder[i] = mapping[val];
		}
									// handled moves for final pinned files
		int numMoves = 0;
		boolean noMove = true;
		for(int i=0; i<p2; i++) {
			if (noMove) {
				if (finalOrder[i] > p1) {	//unpinned becomes pinned
					noMove = false;
					numMoves++;
				}
				else if (i>0 && finalOrder[i] < finalOrder[i-1]) {	// pinned in new order
					noMove = false;
					numMoves += 2;
				}
			}
			else if (finalOrder[i] > p1)
				numMoves++;
			else
				numMoves += 2;
		}
									// handled moves for final unpinned files
		noMove = true;
		for(int i=p2+u2-1; i>=p2; i--) {
			if (noMove) {
				if (finalOrder[i] <= p1) {	// pinned becomes unpinned
					noMove = false;
					numMoves++;
				}
				else if (i<p2+u2-1 && finalOrder[i] > finalOrder[i+1]) {	// unpinned in new order
					noMove = false;
					numMoves += 2;
				}
			}
			else if (finalOrder[i] <= p1)
				numMoves++;
			else
				numMoves += 2;
		}
		System.out.println(numMoves);
	}
}
