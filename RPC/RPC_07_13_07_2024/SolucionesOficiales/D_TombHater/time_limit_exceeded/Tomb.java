import java.util.ArrayList;
import java.util.Scanner;

public class Tomb {

	public static final int MAXD = 100;
	public static final int MAXW = 50;

	public static char[][] grid= new char[MAXD+1][MAXD];
	public static ArrayList<Node>[][] table = new ArrayList[MAXD+2][MAXD];
	public static int rows, cols;
	public static String[] glyphs;
	public static int numG;
	public static Position[][] nodes;

	public static void main(String [] args)
	{
		Scanner in = new Scanner(System.in);
		rows = in.nextInt();
		cols = in.nextInt();
		numG = in.nextInt();
		glyphs = new String[numG];
		nodes = new Position[numG][];
		for(int r=1; r<=rows; r++) {
			for(int c=0; c<cols; c++)
				grid[r][c] = in.next().charAt(0);
		}
		for(int i=0; i<numG; i++) {
			glyphs[i] = in.next();
			nodes[i] = new Position[glyphs[i].length()];
			for(int j=0; j<glyphs[i].length(); j++)
				nodes[i][j] = new Position(i,j);
		}

		Node startNode = new Node(nodes[0][glyphs[0].length()-1],0);		// dummy node to start things off
		for(int c=0; c<cols; c++) {
			table[0][c] = new ArrayList<>();
			table[0][c].add(startNode);
		}
		for(int r=1; r<=rows; r++) {
//			System.out.println("Row " + r);
			for(int c=0; c<cols; c++) {
				table[r][c] = new ArrayList<>();
				for(Node e : table[r-1][c]) {					// check node above
					for(Position f : next(e.p, grid[r][c])) {
//						table[r][c].add(new Node(f, e.dist+1));
						boolean ok = true;
						for(Node g : table[r][c]) {
							if (g.p == f) {
								if (g.dist <= e.dist+1) {
									ok = false;
								}
								else
									table[r][c].remove(g);
								break;
							}
						}
						if (ok)
							table[r][c].add(new Node(f, e.dist+1));
					}
				}
			}
			ArrayList<Node>[] tmp = new ArrayList[cols];
			tmp[0] = new ArrayList<>(table[r][0]);
			for(int c=1; c<cols; c++) {						// sweep to the east
				tmp[c] = new ArrayList<>(table[r][c]);
				for(Node e : tmp[c-1]) {
					for(Position f : next(e.p, grid[r][c])) {
//						tmp[c].add(new Node(f, e.dist+1));
						boolean ok = true;
						for(Node g : tmp[c]) {
							if (g.p == f) {
								if (g.dist <= e.dist+1) {
									ok = false;
								}
								else
									tmp[c].remove(g);
								break;
							}
						}
						if (ok)
							tmp[c].add(new Node(f, e.dist+1));
					}
				}				
			}

			for(int c=cols-2; c>=0; c--) {					// sweep to the west
				for(Node e : table[r][c+1]) {
					for(Position f : next(e.p, grid[r][c])) {
						boolean ok = true;
						for(Node g : table[r][c]) {
							if (g.p == f) {
								if (g.dist <= e.dist+1) {
									ok = false;
								}
								break;
							}
						}
						if (ok)
							table[r][c].add(new Node(f, e.dist+1));
					}
				}

				for(Node e : tmp[c+1])	{					// add in results of east sweep
					boolean ok = true;
					for(Node g : table[r][c+1]) {
						if (g.p == e.p) {
							if (g.dist <= e.dist)ok = false;
						}
					}
					if (ok)
						table[r][c+1].add(e);
				}
			}
			/*
			System.out.println("Final");
			for(int c=0; c<cols; c++) {
				System.out.print("Col " + c + ":");
				for(Node e : table[r][c]) {
					System.out.print(" " + e);
				}
				System.out.println();
			}
			/* */
		}
		int best = rows*cols+1;
		for(int c=0; c<cols; c++) {
			for(Node e : table[rows][c]) {
				if (e.dist < best && e.p.index == glyphs[e.p.iGlyph].length()-1)
					best = e.dist;
			}
		}
		if (best == rows*cols+1)
			System.out.println("Impossible");
		else
			System.out.println(best);
		in.close();
	}

	public static ArrayList<Position> next(Position d, char ch)
	{
		ArrayList<Position> list = new ArrayList<>();
		if (d.index+1 < glyphs[d.iGlyph].length()) {
			if (glyphs[d.iGlyph].charAt(d.index+1) == ch) {
				list.add(nodes[d.iGlyph][d.index+1]);
			}
		}
		else if (startsGlyph(ch)) {
			for(int i=0; i<numG; i++) {
				if (glyphs[i].charAt(0) == ch)
					list.add(nodes[i][0]);
			}		
		}
		return list;
	}

	public static boolean startsGlyph(char ch)
	{
		for(String s : glyphs)
			if (s.charAt(0) == ch)
				return true;
		return false;
	}
}

class Position
{
	public int iGlyph;
	public int index;

	public Position(int iG, int i)
	{
		iGlyph = iG;
		index = i;
	}

	public String toString()
	{
		return "(" + iGlyph + "," + index + ")";
	}
}

class Node
{
	public int dist;
	public Position p;

	public Node(Position p, int d)
	{
		this.p = p;
		dist = d;
	}

	public String toString()
	{
		return ""+dist+p;
	}
}