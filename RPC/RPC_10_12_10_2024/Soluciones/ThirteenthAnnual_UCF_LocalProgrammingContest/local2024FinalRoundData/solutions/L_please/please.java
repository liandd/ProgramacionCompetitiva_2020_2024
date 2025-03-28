
import java.util.*;

public class please {
   final static int CUTOFF = 1;
   final static int NO_CUTOFF = 2;

   public static class student implements Comparable<student> {
      int num, let, pl;
      public int compareTo(student o) {
         if (pl != o.pl) return Integer.compare(o.pl, pl);
         if (let != o.let) return Integer.compare(let, o.let);
         return Integer.compare(num, o.num);
      }
   }
   public static void printAnswer(int[][] g) {
      int gr = 100, let = 4;
      while (let != 0) {
         if (g[let][gr] != NO_CUTOFF) {
            System.out.print(gr);
            System.out.print((--let==0) ? "\n" : " ");
         }
         gr--;
      }
   }

   please() {
      Scanner sc = new Scanner(System.in);
      int n = sc.nextInt();
      student[] sts = new student[n];
      for (int i = 0; i < n; i++) {
         sts[i] = new student();
         sts[i].num = sc.nextInt();
         sts[i].let = 4 + 'A' - sc.next().charAt(0);
         if (sts[i].let == -1) sts[i].let = 0;
         sts[i].pl = sc.nextInt();
      }
      Arrays.sort(sts);
      int[][] tr = new int[5][101], val = new int[5][101];
      for (int i = 0; i < n; i++) {
         var s = sts[i];
         if (s.let <= s.num && 100 - s.num >= 4 - s.let) {
            for (int L = s.let; L < 5; L++) {
               for (int G = s.num; G < 101; G++) {
                  if (L == s.let && G == s.num) {
                     val[L][G]++;
                  } else if (G!=0) {
                     if (tr[L][G] == CUTOFF) {
                         val[L][G] = val[L-1][G-1];
                     } else if (tr[L][G] == NO_CUTOFF) {
                        val[L][G] = val[L][G-1];
                     } else if (L!=0) {
                        val[L][G] = Math.max(val[L][G-1], val[L-1][G-1]);
                     } else {
                        val[L][G] = val[L][G-1];
                     }
                  }
               }
            }
         }
         if (i == n-1 || s.pl != sts[i+1].pl) {
            for (int L = 0; L < 5; L++) {
               for (int G = 0; G < 101; G++) {
                  if (L!=0 && G!=0 && tr[L][G]==0 && val[L][G-1]!=val[L-1][G-1]) {
                     if (val[L][G-1] < val[L-1][G-1]) {
                        tr[L][G] = CUTOFF;
                     } else {
                        tr[L][G] = NO_CUTOFF;
                     }
                  }
               }
            }
            for (int L = 0; L < 5; L++) {
               for (int G = 0; G < 101; G++) {
                  val[L][G] = 0;
               }
            }
         }
      }
      printAnswer(tr);
   }

   public static void main(String[] Args) {
      new please();  
   }
}

