/* Sample solution to "Icons in the Toolbar" from KTH Challenge 2011.
 *
 * Author: Lukas Polacek
 */
import java.io.*;
import java.util.*;

public class IconsSlower {
    public static void main(String[] args) throws IOException {
        Scanner sc = new Scanner(new BufferedInputStream(System.in));
        int n = sc.nextInt();
        int s[] = new int[2 * n];
        for (int i = 0; i < 2 * n; i++)
            s[i] = sc.nextInt();

        long t[] = new long[n];
        t[0] = s[0];
        for (int i = 1; i < n; i++)
            t[i] = s[i] + t[i - 1];
        long u[] = new long[2 * n + 1];
        u[2 * n] = 0;
        for (int i = 2 * n - 2; i >= 0; i--)
            u[i] = s[i] + u[i + 2];

        long res = Long.MAX_VALUE;
        for (int i = 1; i <= n; i++)
            res = Math.min(res, (t[i - 1] + u[2 * i]) * (s[0] + s[i]));

        System.out.println(res);
    }
}
