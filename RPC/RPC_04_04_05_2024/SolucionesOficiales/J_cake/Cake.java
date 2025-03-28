
// Problem: Cut the Cake
// Solution Author: Coach Travis

// Import
import java.util.*;

// The class containing the main method
public class Cake 
{
    // The scanner for reading from standard input
    static Scanner sc = new Scanner(System.in);

    // Method to get the difference of 2 2D vectors
    static int[] diff(int[] a, int[] b) 
    {
        return new int[]{a[0]-b[0],a[1]-b[1]};
    }

    // Method to get the cross product of 2 2D vectors
    static int cross(int[] a, int[] b) 
    {
        return a[0]*b[1] - a[1]*b[0];    
    }

    // Method to get the area of a triangle
    static int triangleArea(int[] a, int[] b, int[] c) 
    {
        int[] d = diff(b, a);
        int[] e = diff(c, a);
        return Math.abs(cross(d, e));
    }
    
    // Method to get the area of a polygon
    static int getArea(ArrayList<int[]>pts) {
        int area = 0;
        for (int i = 0; i < pts.size() - 1; i++) 
        {
            area += triangleArea(pts.get(0), pts.get(i), pts.get(i+1));
        }
        return area;
    }

    // The main method (entry point of the program)
    public static void main(String[] Args) 
    {
        // Read in the number of points
        int n = sc.nextInt();

        // Read in the points
        int[][] pts = new int[n][2];
        for (int i = 0; i < n; i++) 
        {
            pts[i][0] = sc.nextInt();
            pts[i][1] = sc.nextInt();
        }

        // Create variables for holding the answer
        long ans_area_one = 0;
        long ans_area_two = 1000000000;

        // Try all cut pairs
        for (int i = 0; i < n; i++) 
        {
            for (int j = i+2; j < n; j++) 
            {
                // Gen both sides of the cut
                ArrayList<int[]> pts2 = new ArrayList<>();
                for (int k = i; k <= j; k++)
                    pts2.add(pts[k]);
                ArrayList<int[]> pts3 = new ArrayList<>();
                for (int k = j; k != i + 1; k=(k+1)%n)
                    pts3.add(pts[k]);
        
                // Get their areas        
                int a = getArea(pts2);
                int b = getArea(pts3);
                
                // Update answer if it is better
                if (Math.abs(a-b) < Math.abs(ans_area_one-ans_area_two)) 
                {
                    ans_area_one = a;
                    ans_area_two = b;
                }
            }
        }

        // Print the answers
        long smallest = Math.min(ans_area_one, ans_area_two);
        long largest = Math.max(ans_area_one, ans_area_two);
        System.out.printf("%.01f%n", (largest - smallest) / 2.0);
    }
}
