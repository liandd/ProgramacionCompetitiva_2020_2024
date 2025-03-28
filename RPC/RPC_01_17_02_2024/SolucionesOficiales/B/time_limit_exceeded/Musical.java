import java.util.Scanner;

public class Musical {

	public static int[] selection;
	public static int [] times;
	public static int cd1, cd2;
	public static int size;
	
	public static void main(String[] args) {

		Scanner in = new Scanner(System.in);
		int n;

		size = in.nextInt();
		n = in.nextInt();
		times = new int[n];
		for(int i=0; i<n; i++)
			times[i] = in.nextInt();
		selection = new int[n];
		for(int i=0; i<n; i++)
			selection[i] = 0;
		while (true) {
			evaluate(selection);
			increment(selection);
			if (allZeros(selection))
				break;
		}
		System.out.println(Math.max(cd1,  cd2) + " " + Math.min(cd1,  cd2));

	}
	
	public static void evaluate(int [] s)
	{
		int sum1=0, sum2=0;
//		for(int i=0; i<s.length; i++)
//			System.out.print(s[i]);
//		System.out.println();
		for(int i=0; i<s.length; i++) {
			if (s[i] == 1) {
				sum1 += times[i];
				if (sum1 > size)
					return;
			}
			else if (s[i] == 2) {
				sum2 += times[i];
				if (sum2 > size)
					return;
			}
		}
//		System.out.println(sum1 + " " + sum2);
		if (sum1 + sum2 > cd1 + cd2) {
			cd1 = sum1;
			cd2 = sum2;
		}
		else if (sum1+sum2 == cd1+cd2 && Math.abs(sum1-sum2) < Math.abs(cd1-cd2)) {
			cd1 = sum1;
			cd2 = sum2;
		}
	}
	
	public static void increment(int[] s)
	{
		for(int i=0; i<s.length; i++) {
			s[i]++;
			if (s[i] == 3)
				s[i] = 0;
			else
				break;
		}
	}
	
	public static boolean allZeros(int [] s)
	{
		for(int val : s) {
			if (val != 0)
				return false;
		}
		return true;
	}

}