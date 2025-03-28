//
// 2024 UCF Local Programming Contest (Final Round) -- adapter
// Ali Orooji
//

import java.util.*;
import java.lang.Math;

public class adapter
{
	public static int tree_amp;
	
	public static int candidate_watt;
	public static int candidate_volt;
	public static int candidate_amp;

   /* ********************************************************* */
	
   public static void main(String[] args)
   {
	  Scanner input = new Scanner(System.in);
	  
	  tree_amp = input.nextInt();
	  
	  candidate_watt = input.nextInt();
	  candidate_volt = input.nextInt();
	  
	  candidate_amp = candidate_watt / candidate_volt;
	  
	  if (candidate_amp >= tree_amp)
		  System.out.println("1");
	  else
		  System.out.println("0");
	   
   }// end of main()

   /* ********************************************************* */
 
}// end of class adapter

   /* ********************************************************* */
