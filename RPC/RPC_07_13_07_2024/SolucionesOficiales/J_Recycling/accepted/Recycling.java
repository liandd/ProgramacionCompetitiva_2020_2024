import java.util.Scanner;
import java.util.Stack;

public class Recycling {

	public static void main(String[] args) {

		Stack<StackElement> s = new Stack<>();
		Scanner in = new Scanner(System.in);

		int n = in.nextInt();
		int height;
		s.push(new StackElement(0, 0));
		long bestArea = 0;
		int bestStart = 0, bestEnd = 0;
		StackElement e = null;
		for(int i=1; i<=n; i++) {
			height = in.nextInt();
			e = null;
			while (!s.empty() && height < s.peek().height) {
				e = s.pop();
				//System.out.println(" pop " + e.height + "," + e.start);
				long area = e.height*(long)(i-e.start);
				if (area > bestArea) {
					bestArea = area;
					bestStart = e.start;
					bestEnd = i;
				}
				else if (area == bestArea && e.start < bestStart) {
					bestStart = e.start;
					bestEnd = i;
				}
			}
			if (e == null)	
				s.push(new StackElement(height, i));
			else	
				s.push(new StackElement(height, e.start));
//			System.out.println("push " + s.peek().height + "," + s.peek().start);
		}
		while (s.size() > 1) {
			e = s.pop();
//			System.out.println("pop " + e.height + "," + e.start);
			long area = e.height*(long)(n+1-e.start);
			if (area >= bestArea) {
				bestArea = area;
				bestStart = e.start;
				bestEnd = n+1;
			}
		}
		System.out.println(bestStart + " " + (bestEnd-1) + " " + bestArea);

	}

}

class StackElement
{
	public int height;
	public int start;

	public StackElement(int height, int start)
	{
		this.height = height;
		this.start = start;
	}
}
