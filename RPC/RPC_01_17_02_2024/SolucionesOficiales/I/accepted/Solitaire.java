import java.util.Scanner;

public class Solitaire {

	public static Scanner in = new Scanner(System.in);
	public static Card [] hand = new Card[52];
	public static final boolean DEBUG = false;

	public static void main(String[] args) {

		int j = 0, i=0;
		boolean dealCard = true;
		while (i < 52 || !dealCard) {
			if (dealCard) {
				String s = in.next();
				hand[j] = new Card(s.charAt(0), s.charAt(1));
				if (DEBUG) printHand(j+1);
				i++;
			}
			dealCard = false;
//			if (DEBUG && j >=0) System.out.println("top card = " + hand[j]);
			int k=j-3;
			while (k >=0 && hand[k].rank != hand[k+3].rank)
				k--;
			if (k >= 0) {
if (DEBUG) System.out.println(" -- 4-remove: " + hand[k] + " to " + hand[k+3]);
				for(; k<=j-4; k++)
					hand[k] = hand[k+4];
				j -= 4;
				if (DEBUG) printHand(j+1);
				continue;
			}
			k=j-3;
			while (k >=0 && hand[k].suit != hand[k+3].suit)
				k--;
			if (k >= 0) {
				if (DEBUG) System.out.println(" -- 2-remove: " + hand[k] + " and " + hand[k+3]);
				hand[k] = hand[++k];
				hand[k] = hand[++k];
				for(; k<=j-2; k++)
					hand[k] = hand[k+2];
				j -= 2;
				if (DEBUG) printHand(j+1);
				continue;
			}
			if (DEBUG) System.out.println();
			dealCard = true;
			j++;
			//				if (DEBUG) printHand(j);
		}
		printHand(j);
		System.out.println();
	}

	public static void printHand(int num)
	{
		System.out.print(num);
		for(int i=0; i<num; i++) {
			System.out.print(" " + hand[i]);
		}
//		System.out.println();

	}

}

class Card
{
	char rank, suit;

	public Card(char r, char s)
	{
		rank = r;
		suit = s;
	}

	public String toString()
	{
		return ""+rank+suit;
	}
}
