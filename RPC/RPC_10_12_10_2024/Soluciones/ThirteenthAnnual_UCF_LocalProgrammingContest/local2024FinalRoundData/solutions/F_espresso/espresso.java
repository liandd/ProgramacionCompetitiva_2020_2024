import java.util.*;
import java.io.*;

public class espresso {
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        long n1 = sc.nextLong();
        long d1 = sc.nextLong();
        long n2 = sc.nextLong();
        long d2 = sc.nextLong();

        // convert from ratios to fracts
        d1 += n1;
        d2 += n2;

        if(!(n1 * d2 <= n2 * d1)){
            // swap nums
            long temp = n1;
            n1 = n2;
            n2 = temp;

            // swap dens
            temp = d1;
            d1 = d2;
            d2 = temp;
        }

        for(long ans = 0; ; ++ans){
            long den = 1L << ans;

            // num/den: biggest fract <= n2/d2
            long num = n2 * den / d2;

            // check if n1/d1 <= num/den
            if(n1 * den <= num * d1){
                System.out.println(ans);
                break;
            }
        }
    }
}