
// Problem: Easy Problem
// Author:  Coach Travis

// Import the scanner for reading from the user
import java.util.Scanner;

// The class containing the main method
public class Peasy 
{
    // The main method
    public static void main(String[] Args) 
    {
        // Open a scanner for reading from the standard input
        Scanner sc = new Scanner(System.in);

        // Read in the number of contestants that solve the problem at the 
        // halfwaya and last hour
        int h2 = sc.nextInt();
        int h4 = sc.nextInt();
        
        // Check if number of solutions at the 2nd hour is at least half 
        // the total (hour 4)
        if (h2 * 2 >= h4) 
        {
            // Inform the user that the problem was easy
            System.out.println("E");
        }
        else
        {
            // The problem was hard let the user know
            System.out.println("H");
        }

        // Close the scanner
        sc.close();
    }
}
