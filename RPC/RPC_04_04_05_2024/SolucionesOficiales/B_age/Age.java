//
// 2023 UCF Local Programming Contest (Qualifying Round) -- age
// Ali Orooji
//

import java.util.*;
import java.lang.Math;

public class Age
{
	public static final int MAX_AGE = 150;
	
	public static int orooji, alyssa, konari;
	
	public static Scanner input;
	
   /* ********************************************************* */
	
   public static void main(String[] args)
   {
	  input = new Scanner(System.in);
	  
	  // read the three input values (ages)
	  orooji = input.nextInt();
	  alyssa = input.nextInt();
	  konari = input.nextInt();
	  
	  // find and print the result
	  System.out.println(solve());
	   
   }// end of main()

   /* ********************************************************* */
	
   public static int solve()
   {
	  for (int a = 1;  a <= MAX_AGE;  ++a)
		  for (int k = 1;  k <= MAX_AGE;  ++k)
			  if ( orooji == ((a * alyssa) + (k * konari)) )
				  return(1);
	  
	  return(0);
	   
   }// end of solve()

   /* ********************************************************* */
 
}// end of class age

   /* ********************************************************* */
