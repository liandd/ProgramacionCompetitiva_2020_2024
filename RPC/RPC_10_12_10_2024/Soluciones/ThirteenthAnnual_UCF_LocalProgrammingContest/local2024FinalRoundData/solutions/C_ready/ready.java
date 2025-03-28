//
// 2024 UCF Local Programming Contest (Final Round) -- ready
// Ali Orooji
//

import java.util.*;
import java.lang.Math;

public class ready
{
   public static int num_of_problems;
   public static int num_of_solutions;
	
   public static boolean ready_solution[][];
	
   /* ********************************************************* */
	
   public static void main(String[] args)
   {
	  Scanner input = new Scanner(System.in);
	  
	  read_process_input(input);
	  
	  print_results();
	   
   }// end of main()

   /* ********************************************************* */
  
   public static void read_process_input(Scanner input)
   {
	   num_of_problems  = input.nextInt();
	   num_of_solutions = input.nextInt();
	   
	   ready_solution = new boolean[num_of_problems + 1][3 + 1];
	                          /* [0][] and [][0] not used to simplify the code
							     [][1] flag for C++
								 [][2] flag for Java
								 [][3] flag for Python though not needed! */
	   
	   for (int p = 1;  p <= num_of_problems;  ++p)
	   {
		   Arrays.fill(ready_solution[p], false);
	   }
	   
	   // process input solutions
	   for (int s = 1;  s <= num_of_solutions;  ++s)
	   {
		   int prob = input.nextInt();
		   int lang = input.nextInt();
		   
		   ready_solution[prob][lang] = true;
		   
	   }// end for (s)
	  
   }// end of read_process_input()
  
   /* ********************************************************* */
	
   public static void print_results()
   {
	   for (int p = 1;  p <= num_of_problems;  ++p)
	   {
		   if ( (ready_solution[p][1]) && (ready_solution[p][2]) )
		   {
			   // there are solutions in C++ and Java
			   System.out.println(p);
		   }
	   }

   }// end of print_results()

   /* ********************************************************* */
 
}// end of class ready

   /* ********************************************************* */
