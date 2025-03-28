//
// 2024 UCF Local Programming Contest (Final Round) -- phone
// Ali Orooji
//

import java.util.*;
import java.lang.Math;

public class phone
{
	public static final int NUM_OF_DIGITS = 10;
	public static final String DIGITS = "0123456789";
	
	public static String phone_num;

   /* ********************************************************* */
	
   public static void main(String[] args)
   {
	  Scanner input = new Scanner(System.in);
	  
	  phone_num = input.next();
	  
	  System.out.println( count_distinct() );
	   
   }// end of main()

   /* ********************************************************* */
	
   public static int count_distinct()
   {
	  int count = 0;
	  for (int k = 0;  k < NUM_OF_DIGITS;  ++k)
	  {
		  if ( phone_num.indexOf(DIGITS.charAt(k)) >= 0 )
		  {
			  // this digit is in the phone number
			  ++count;
		  }
		  
	  }// end for (k)
	  
	  return(count);
	   
   }// end of count_distinct()

   /* ********************************************************* */
 
}// end of class phone

   /* ********************************************************* */
