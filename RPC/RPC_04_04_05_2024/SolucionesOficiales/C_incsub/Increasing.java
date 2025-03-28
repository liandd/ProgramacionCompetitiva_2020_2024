//
// 2023 UCF Local Programming Contest (Qualifying Round) -- incsub
// Ali Orooji
//

import java.util.*;
import java.lang.Math;

public class Increasing
{
	public static int list_size;
	
	public static int list[];
	
   /* ********************************************************* */
	
   public static void main(String[] args)
   {
	  Scanner input = new Scanner(System.in);
	  
	  read_and_init(input);
	  System.out.println(find_longest());
	   
   }// end of main()

   /* ********************************************************* */
   
   public static void read_and_init(Scanner input)
   {  
	   list_size = input.nextInt();
	   
	   list = new int[list_size + 1]; // [0] not used
	   
	   for (int k = 1;  k <= list_size;  ++k)
	   {
		   list[k] = input.nextInt();
	   }
	  
   }// end of read_and_init()
  
   /* ********************************************************* */
	
   public static int find_longest()
   {
	  int longest_length = 1;
	  int curr_length = 1;
	  int index  = 1;
	  
	  while ((index + 1) <= list_size)
	  {
		  while ( ((index + 1) <= list_size) && 
		          (list[index] < list[index + 1]) )
		  {
			  ++curr_length;
			  ++index;
		  }
		  
		  if (curr_length > longest_length)
			  longest_length = curr_length;
		  
		  curr_length = 1;
		  ++index;
		  
	  }// end while
	  
	  return(longest_length);
	   
   }// end of find_longest()

   /* ********************************************************* */
 
}// end of class incsub

   /* ********************************************************* */
