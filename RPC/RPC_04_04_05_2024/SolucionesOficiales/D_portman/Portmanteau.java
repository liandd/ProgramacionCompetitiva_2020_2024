//
// 2023 UCF Local Programming Contest (Qualifying Round) -- portman
// Ali Orooji
//

import java.util.*;
import java.lang.Math;

public class Portmanteau
{
	public static final String VOWELS = "aeiou";
	
	public static final int MAX_WORD_LENGTH = 20;
	
	public static final int NOT_EXIST = (-100);
	
	public static int word_length[];
	
	public static char word[][];
	
	public static int end_point[];
	
   /* ********************************************************* */
	
   public static void main(String[] args)
   {
	  Scanner input = new Scanner(System.in);
	  
	  read_and_init(input);
	  find_end_points();
	  print_portmanteau();
	   
   }// end of main()

   /* ********************************************************* */
  
   public static void read_and_init(Scanner input)
   {
	   word_length = new int[2];
	   word = new char[2][MAX_WORD_LENGTH + 1];
	   
	   for (int k = 0;  k <= 1;  ++k)
	   {
		   String word_str = input.next();
		   word_length[k] = word_str.length();
		   word[k] = word_str.toCharArray();
		   
	   }// end for (k)
		   
	   end_point = new int[2];
	   Arrays.fill(end_point, NOT_EXIST);
	  
   }// end of read_and_init()
  
   /* ********************************************************* */
	
   public static void find_end_points()
   {
	  // find end_point[0]
	  for (int k = 1;  k < word_length[0];  ++k)
		  if ( VOWELS.indexOf(word[0][k]) >= 0 )
		  {
			  end_point[0] = k;
			  break;
		  }
	  
	  // find end_point[1]
	  for (int k = word_length[1] - 2;  k >= 0;  --k)
		  if ( VOWELS.indexOf(word[1][k]) >= 0 )
		  {
			  end_point[1] = k;
			  break;
		  }
	   
   }// end of find_end_points()
  
   /* ********************************************************* */
	
   public static void print_portmanteau()
   {
	  // print letters from word[0]
	  int last_index = end_point[0];
	  if (last_index == NOT_EXIST)
		  last_index = word_length[0];
	  
	  for (int k = 0;  k < last_index;  ++k)
		  System.out.print(word[0][k]);
	  
	  // print the merging vowel
	  if (end_point[1] != NOT_EXIST)
		  System.out.print(word[1][end_point[1]]);
	  else if (end_point[0] != NOT_EXIST)
		  System.out.print(word[0][end_point[0]]);
	  else
		  System.out.print("o");
	  
	  // print letters from word[1]
	  last_index = end_point[1];
	  if (last_index == NOT_EXIST)
		  last_index = -1;
	  
	  for (int k = last_index + 1;  k <= word_length[1] - 1;  ++k)
		  System.out.print(word[1][k]);
	  
	  System.out.println();
	   
   }// end of print_portmanteau()

   /* ********************************************************* */
 
}// end of class portman

   /* ********************************************************* */
