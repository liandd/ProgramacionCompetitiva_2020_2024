import java.util.ArrayList;
import java.util.Random;
import java.util.Scanner;

public class Pattern {

	public static void main(String [] args)
	{
		Scanner in = new Scanner(System.in);
		
		String s = in.next();
		String target = in.next();
		ArrayList<String> strings = new ArrayList<>();
		strings.add(s);
		boolean stop = false;
		for(int i=1; i<=100; i++) {
			if (s.equals(target)) {
				System.out.println(i);
				stop = true;
				break;
			}
			s = next(s);
			for(String t : strings) {
				if (t.equals(s)) {
					System.out.println("Does not appear");
					stop = true;
				}
			}
			if (stop)
				break;
			else
				strings.add(s);
		}
		if (!stop) {				// went 100 iterations with no repeats
			System.out.println("Can't use this input");
		}
	}
	
	public static String next(String s)
	{
		int [] digits = new int[10];
		String ans="";
		
		for(int i=0; i<s.length(); i++) {
			digits[Integer.parseInt(s.substring(i, i+1))]++;
		}
		for(int d=0; d<10; d++) {
			if (digits[d] != 0)
				ans += ""+digits[d]+d;
		}
		
		return ans;
	}

}
