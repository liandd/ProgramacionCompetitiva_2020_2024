import java.util.*;

public class Spumbers {
  public static void main(String[] args) {
    String big = ""+Integer.MAX_VALUE;
    Scanner in = new Scanner(System.in);
    String[] line = in.nextLine().split(" ");
    String xs = line[0];
    String ys = line[2];
    String zs = line[4];
    int xlen = xs.length();
    int ylen = ys.length();
    int zlen = zs.length();
    String op = line[1];
    int x = Integer.parseInt(xs);
    int y = Integer.parseInt(ys);
    int z = Integer.parseInt(zs);
    // x, y:
    for (int i = 1; i < xlen; i++) {
      String x1 = xs.substring(0,i);
      String x2 = xs.substring(i);
      for (int j = 1; j < ylen; j++) {
        String y1 = ys.substring(0,j);
        String y2 = ys.substring(j);
        if (comp(y1+x2,big) > 0 || comp(x1+y2,big) > 0) continue;
        int xt = Integer.parseInt(y1+x2);
        int yt = Integer.parseInt(x1+y2);
        if (op.equals("*") && xt*yt == z) {
          System.out.printf("%d * %d = %d\n",xt,yt,z);
          System.exit(0);
        }
        if (op.equals("+") && xt+yt == z) {
          System.out.printf("%d + %d = %d\n",xt,yt,z);
          System.exit(0);
        }
      }
    }
    // x, z:
    for (int i = 1; i < xlen; i++) {
      String x1 = xs.substring(0,i);
      String x2 = xs.substring(i);
      for (int j = 1; j < zlen; j++) {
        String z1 = zs.substring(0,j);
        String z2 = zs.substring(j);
        if (comp(z1+x2,big) > 0 || comp(x1+z2,big) > 0) continue;
        int xt = Integer.parseInt(z1+x2);
        int zt = Integer.parseInt(x1+z2);
        if (op.equals("*") && xt*y == zt) {
          System.out.printf("%d * %d = %d\n",xt,y,zt);
          System.exit(0);
        }
        if (op.equals("+") && xt+y == zt) {
          System.out.printf("%d + %d = %d\n",xt,y,zt);
          System.exit(0);
        }
      }
    }
    // y, z:
    for (int i = 1; i < ylen; i++) {
      String y1 = ys.substring(0,i);
      String y2 = ys.substring(i);
      for (int j = 1; j < zlen; j++) {
        String z1 = zs.substring(0,j);
        String z2 = zs.substring(j);
        if (comp(z1+y2,big) > 0 || comp(y1+z2,big) > 0) continue;
        int yt = Integer.parseInt(z1+y2);
        int zt = Integer.parseInt(y1+z2);
        if (op.equals("*") && x*yt == zt) {
          System.out.printf("%d * %d = %d\n",x,yt,zt);
          System.exit(0);
        }
        if (op.equals("+") && x+yt == zt) {
          System.out.printf("%d + %d = %d\n",x,yt,zt);
          System.exit(0);
        }
      }
    }
  }


  public static int comp(String x, String y) {
    int xl = x.length(), yl = y.length();
    if (xl == yl) return x.compareTo(y);
    else if (xl < yl) {
      String z = "000000000000000000000".substring(0,yl-xl);
      return (z+x).compareTo(y);
    }
    else {
      String z = "000000000000000000000".substring(0,xl-yl);
      return x.compareTo(z+y);
    }
  }
}
