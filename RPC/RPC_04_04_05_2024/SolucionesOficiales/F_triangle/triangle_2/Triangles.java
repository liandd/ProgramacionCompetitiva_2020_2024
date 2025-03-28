
// Problem: Close Triangles
// Solution Author: Coach Travis

// Import the class for the scanner
import java.util.*;

// The class containing the main method
public class Triangles 
{
    // The scanner for reading in from standard input
    static Scanner sc = new Scanner(System.in);

    // The array of precomputed triangle areas
    static int[][][] precomp;

    // The method for swapping values in an array
    static void swap(int[] arr, int i, int j) 
    {
        // Check if there is no actual swap
        if (i == j) return;

        // Swap using a temp value
        int tmp = arr[i];
        arr[i] = arr[j];
        arr[j] = tmp;
    }

    // The function to recursively select different triangles
    static int recurse(int min, int max, int[] rem, int left) 
    {
        int i;
        int j;
        int k;
        int area;
        int ans;

        // Start answer as an impossibly high value
        ans = Integer.MAX_VALUE;

        // Check if all the points have been choosen
        if (left == 0) {
            ans = max - min;
            return max - min;
        }
        
        // Use the first point in the current triangle
        for (i = 0; i < left - 2; i++) 
        {
            // Move the first point to the end
            swap(rem, 0, left-1);

            // Try all possible second points without reusing the first 1
            for (j = i; j < left - 2; j++) 
            {
                // Move the second point to the end
                swap(rem, j, left-2);

                // Try all possible third points without reusing the first 2
                for (k = j; k < left - 2; k++) 
                {
                    // Move the third point to the end
                    swap(rem, k, left-3);

                    // Compute the area based on the three selected values
                    area = precomp[rem[left-1]][rem[left-2]][rem[left-3]];

                    // Compute the new min and new max
                    int newMin = Math.min(min, area);
                    int newMax = Math.max(max, area);

                    // Compute the best answer recursively and adjust the 
                    // current answer based on the result
                    ans = Math.min(ans, recurse(newMin, newMax, rem, left-3));
                    
                    // Reinsert the third point
                    swap(rem, k, left-3);
                }
                // Reinsert the second point
                swap(rem, j, left-2);
            }
            // Reinsert the first point
            swap(rem, i, left-1);
        }

        return ans;
    }

    // The method to precomp all the triangles
    public static void runPrecomp(int[][] pts) 
    {
        // Get the number of points
        int n = pts.length;

        // Allocate the memory
        precomp = new int[n][n][n];

        // Find all triplets
        for (int i = 0; i < n; i++) 
        {
            for (int j = 0; j < n; j++) 
            {
                for (int k = 0; k < n; k++) 
                {
                    // Get vector from i to j
                    int x1 = pts[j][0]-pts[i][0];
                    int y1 = pts[j][1]-pts[i][1];

                    // Get vector from i to k
                    int x2 = pts[k][0]-pts[i][0];
                    int y2 = pts[k][1]-pts[i][1];

                    // Cross and store result in precomp table
                    precomp[i][j][k] = Math.abs(x1*y2 - x2*y1);
                }
            }
        } 
    }

    // The main method (program's entry point
    public static void main(String[] Args) 
    {
        // Read in the number of triangles
        int n = sc.nextInt();
        
        // Read in all the points
        int[][] pts = new int[n * 3][2];
        for (int i = 0; i < n * 3; i++) 
        {
            pts[i][0] = sc.nextInt();
            pts[i][1] = sc.nextInt();
        }

        // Create the permutation array
        int[] perm = new int[n * 3];
        for (int i = 0; i < n * 3; i++)
        {
            perm[i] = i;
        }

        // Precomp
        runPrecomp(pts);

        // Get the best difference in area
        int answer = recurse(Integer.MAX_VALUE, Integer.MIN_VALUE, perm, n * 3);

        // Print the answer
        System.out.printf("%.01f%n", answer / 2.0);
    }
}
