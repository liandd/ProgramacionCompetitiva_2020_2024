import java.util.ArrayList;
import java.util.Scanner;

public class Abridged {

	public static int max  = 0;;
	public static final int MAXN = 1000;
	
	public static Node[] nodes = new Node[MAXN+1];

	
	public static Tuple process(Node n)
	{
		if (n.children.size() == 0) {
//System.out.println("node size " + n.value + ", return " + n.value + "," + max);
			return new Tuple(n.value, max); 
		}
		else {
			Tuple tmp = process(n.children.get(0));
			int min1a = tmp.min1;
			int min1b = max;
			int min2 = tmp.min2;
			for(int i=1; i<n.children.size(); i++) {
				tmp = process(n.children.get(i));
				if (tmp.min1 <= min1a) {
					min1b = min1a;
					min1a = tmp.min1;
				}
				else if (tmp.min1 < min1b)
					min1b = tmp.min1;
				if (tmp.min2 < min2)
					min2 = tmp.min2;
			}
			if (min1b != max && min1a + min1b < min2)
				min2 = min1a + min1b;
//System.out.println("node size " + n.value + ", return " + (min1a+n.value) + "," + (min2+n.value));
			return new Tuple(min1a+n.value, min2+n.value);
		}
	}
	
	public static void main(String[] args) {

		int n, m;
		Scanner in = new Scanner(System.in);
		
		n = in.nextInt();
		m = in.nextInt();
		
		for(int i=1; i<=n; i++) {
			nodes[i] = new Node();
			nodes[i].value = in.nextInt();
			max += nodes[i].value;
		}
		for(int i=0; i<m; i++) {
			int p = in.nextInt();
			int c = in.nextInt();
			nodes[p].children.add(nodes[c]);
			nodes[c].hasParent = true;
		}
		nodes[0] = new Node();
		for(int i=1; i<=n; i++) {
			if (!nodes[i].hasParent)
				nodes[0].children.add(nodes[i]);
		}
		Tuple ans = process(nodes[0]);
		System.out.println(ans.min2);
	}

}

class Tuple
{
	public int min1, min2;
	
	public Tuple(int a, int b)
	{
		min1 = a;
		min2 = b;
	}
}

class Node
{
	public ArrayList<Node> children = new ArrayList<>();
	public int value;
	public boolean hasParent = false;
}
