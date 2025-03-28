import java.util.ArrayList;
import java.util.Comparator;
import java.util.Scanner;

public class Charts {

	public static String s;
	public static int index;
	public static Comparator<Node> comp = new NodeComparator();

	public static void main(String[] args) {

		Scanner in = new Scanner(System.in);

		s = in.nextLine();
		s = s.replaceAll(" ", "");
		index = 0;
		Node tree1 = buildTree();
		sortTree(tree1);
		
		s = in.nextLine();
		s = s.replaceAll(" ", "");
		index = 0;
		Node tree2 = buildTree();
		sortTree(tree2);
		
		//printTree(tree1);
		//printTree(tree2);

		if (sameTree(tree1, tree2))
			System.out.println("Yes");
		else
			System.out.println("No");
	}

	public static Node buildTree()
	{
		int val = 0;

		while(index < s.length() && Character.isDigit(s.charAt(index))) {
			val = 10*val + (s.charAt(index)-'0');
			index++;
		}
		Node t = new Node(val);
		while (index < s.length() && s.charAt(index) != ')') {
			index++;				// skip over '('
			t.children.add(buildTree());
		}
		index++;
		return t;
	}
	
	public static void sortTree(Node t)
	{
		t.children.sort(comp);
		for(Node c : t.children)
			sortTree(c);
	}
	
	public static boolean sameTree(Node t1, Node t2)
	{
		if (t1.num != t2.num)
			return false;
		if (t1.children.size() != t2.children.size())
			return false;
		for(int i=0; i<t1.children.size(); i++) {
			if (!sameTree(t1.children.get(i), t2.children.get(i)))
				return false;
		}
		return true;
	}
	
	public static void printTree(Node t)
	{
		if (t == null)
			return;
		System.out.print("Node " + t.num + ":");
		for(Node c : t.children)
			System.out.print(" " + c.num);
		System.out.println();
		for(Node c : t.children)
			printTree(c);
	}
}

class Node
{
	public int num;
	ArrayList<Node> children;

	public Node(int num) {
		this.num = num;
		children = new ArrayList<>();
	}
}

class NodeComparator implements Comparator<Node>
{
	
	public int compare(Node n1, Node n2)
	{
		return n1.num - n2.num;
	}
}
