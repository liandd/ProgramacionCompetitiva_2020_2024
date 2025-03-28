// Arup Guha
// 8/19/2024
// Verifier for 2024 UCF Locals Problem: Magnetic Attraction

import java.util.*;

public class magnetic {

	public static void main(String[] args) {
	
		// Just going to use doubles anyway...
		// Read in weaker magnet.
		Scanner stdin = new Scanner(System.in);
		double s1 = stdin.nextDouble();
		double x1 = stdin.nextDouble();
		double y1 = stdin.nextDouble();
		
		// Stronger one.
		double s2 = stdin.nextDouble();
		double x2 = stdin.nextDouble();
		double y2 = stdin.nextDouble();
		
		// Distance between the magnets.
		double d = Math.sqrt((x2-x1)*(x2-x1) + (y2-y1)*(y2-y1));
		
		// An important ratio.
		double ratio = Math.sqrt(s2/s1);
		
		// This is the distance from the weaker magnet to the equilibrium point on the
		// line segment connecting the magnets.
		double dToPt1 = d/(ratio + 1);
		
		// This is the distance from the weaker magnet to the equilibrium point on the line
		// between the two magnets, but not on the segment (so going from the weaker magnet
		// moving directly away from both magnets.
		double dToPt2 = d/(ratio - 1);
		
		// The area we want is a circle where these two points are the ends of the diameter.
		double r = (dToPt1+dToPt2)/2;
		double pi = Math.acos(0)*2;
		System.out.printf("%.9f\n",pi*r*r);
	}
}