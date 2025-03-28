import java.util.Scanner;

public class Spumbers {

	public static final boolean CHECKALL = true;

	public static void main(String [] args)
	{
		String val1, op, val2, val3;
		Scanner in = new Scanner(System.in);

		val1 = in.next();
		op = in.next();
		val2 = in.next();
		in.next();				// skip =
		val3 = in.next();

		for(int i1=1; i1<val1.length(); i1++) {
			String val1a = val1.substring(0,i1);
			String val1b = val1.substring(i1);
			for(int i2=1; i2<val2.length(); i2++) {
				String val2a = val2.substring(0,i2);
				String val2b = val2.substring(i2);
				if (ok(val2a+val1b, val1a+val2b, val3, op)) {
					System.out.println(val2a+val1b+" "+op+" "+val1a+val2b+" = " + val3);
					if (!CHECKALL) System.exit(0);
				}
			}
			for(int i3=1; i3<val3.length(); i3++) {
				String val3a = val3.substring(0,i3);
				String val3b = val3.substring(i3);
				if (ok(val3a+val1b, val2, val1a+val3b, op)) {
					System.out.println(val3a+val1b+" "+op+" "+val2+" = " + val1a+val3b);
					if (!CHECKALL) System.exit(0);
				}
			}
		}
		for(int i2=1; i2<val2.length(); i2++) {
			String val2a = val2.substring(0,i2);
			String val2b = val2.substring(i2);
			for(int i3=1; i3<val3.length(); i3++) {
				String val3a = val3.substring(0,i3);
				String val3b = val3.substring(i3);
				if (ok(val1, val3a+val2b, val2a+val3b, op)) {
					System.out.println(val1+" "+op+" "+val3a+val2b+" = " + val2a+val3b);
					if (!CHECKALL) System.exit(0);
				}
			}
		}
	}


	public static boolean ok(String val1, String val2, String val3, String op)
	{
		long v1 = Long.parseLong(val1);
		long v2 = Long.parseLong(val2);
		long v3 = Long.parseLong(val3);
		if (op.equals("+"))
			return (v1+v2 == v3);
		else
			return (v1*v2 == v3);
	}
}
