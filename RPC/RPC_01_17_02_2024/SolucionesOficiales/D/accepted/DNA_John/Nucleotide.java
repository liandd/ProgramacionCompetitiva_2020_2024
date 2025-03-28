import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Scanner;
import java.util.StringTokenizer;

public class Nucleotide {

	public static final int NUMCHARS = 4;
	public static final char[] letters = {'A', 'T', 'G', 'C'};
	public static Scanner sin = new Scanner(System.in);
	
	public static int [][] segtrees = new int[NUMCHARS][];
	public static String s;
	public static int len;
	
	public static void main(String [] args) throws IOException
	{
		BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
		s = in.readLine();
		double log2 = Math.log(s.length())/Math.log(2);
		if ((int)log2 != log2)
			log2++;
		len = (int)Math.pow(2, (int)log2);
//		System.out.println(len);
		for(int i=0; i<NUMCHARS; i++)
			segtrees[i] = new int[2*len-1];
		buildTrees(0, 0, s.length()-1, len);
/*
		System.out.println(s);
		for(int i=0; i<NUMCHARS; i++) {
			for(int j=0; j<segtrees[i].length; j++) {
				System.out.print(segtrees[i][j] + " ");
			}
			System.out.println();
		}
*/
		int m = Integer.parseInt(in.readLine());
		StringTokenizer st = new StringTokenizer(in.readLine());
		int low, high;
		for(int i=0; i<m; i++) {
			while (!st.hasMoreTokens())
				st = new StringTokenizer(in.readLine());
			low = Integer.parseInt(st.nextToken());
			while (!st.hasMoreTokens())
				st = new StringTokenizer(in.readLine());
			high = Integer.parseInt(st.nextToken());
			processQuery(low, high);
		}
	}
	
	public static void buildTrees(int index, int low, int high, int len)
	{
//		System.out.println(index + " " + low + " " + high + " " + len);
		if (len == 0) System.exit(0);
		if (high-low == 0  && low < s.length()) {
			switch (s.charAt(low)) {
			case 'A' : segtrees[0][index] = 1; break;
			case 'T' : segtrees[1][index] = 1; break;
			case 'G' : segtrees[2][index] = 1; break;
			case 'C' : segtrees[3][index] = 1; break;
			}
		}
		else if (high > low) {
			len /= 2;
			int mid = low+len-1;
			buildTrees(2*index+1, low, mid, len);
			buildTrees(2*index+2, mid+1, high, len);
			for(int i=0; i<NUMCHARS; i++) {
				segtrees[i][index] = segtrees[i][2*index+1] + segtrees[i][2*index+2];
			}
		}
	}
	
	static class Tuple
	{
		public int[] count = new int[NUMCHARS];
	}
	
	public static void processQuery(int low, int high)
	{
		Tuple counts = new Tuple();
		processQuery(0, low-1, high-1, 0, len-1, counts);
		for(int i=0; i<NUMCHARS; i++) {
			int max = 0;
			for(int j=1; j<NUMCHARS; j++)
				if (counts.count[j] > counts.count[max])
					max = j;
			System.out.print(letters[max]);
			counts.count[max] = -1;
		}
		System.out.println();
	}
	
	public static void processQuery(int index, int low, int high, int rangelow, int rangehigh, Tuple ans)
	{
//		System.out.println(index + " " + low + " " + high + " " + rangelow + " " + rangehigh);
//		String s;
//		s = sin.nextLine();
		if (low == rangelow && high == rangehigh) {
			for(int i=0; i<NUMCHARS; i++)
				ans.count[i] = segtrees[i][index];
			return;
		}
		if (low > high)
			return;
		int mid = (rangelow+rangehigh)/2;
		if (low > mid)
			processQuery(2*index+2, low, high, mid+1, rangehigh, ans);
		else if (high < mid)
			processQuery(2*index+1, low, high, rangelow, mid, ans);
		else {
			processQuery(2*index+1, low, mid, rangelow, mid, ans);
			Tuple tmp = new Tuple();
			processQuery(2*index+2, mid+1, high, mid+1, rangehigh, tmp);
			for(int i=0; i<NUMCHARS; i++)
				ans.count[i] += tmp.count[i];
		}
	}
}
