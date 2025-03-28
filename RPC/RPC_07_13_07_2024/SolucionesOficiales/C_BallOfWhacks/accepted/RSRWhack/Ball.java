import java.util.*;

public class Ball {
//  public static Integer[][] s; // the three input pieces
  public static HashSet<ArrayList<Integer>> trans; // all transformations
  public static Integer[][] tr; // all transformations (sorted)
  public static HashSet<Integer> faces;

  public static void main(String[] args) {
    trans = new HashSet<ArrayList<Integer>>();
    tr = new Integer[60][30];

    // Identity transformation:
    Integer id[] = new Integer[30];
    for (int i = 0; i < 30; i++) id[i] = i;

    // Use rotations about a degree-5 vertex and rotations around
    // two different degree-3 vertices as generators:
    Integer five[][] = new Integer[4][30];
    Integer three1[][] = new Integer[2][30];
    Integer three2[][] = new Integer[2][30];

    five[0] = new Integer[]{1,2,3,4,0,6,7,8,9,5,12,13,14,15,16,17,18,19,10,11,
                      21,22,23,24,20,26,27,28,29,25};
    
    three1[0] = new Integer[]{29,24,18,17,23,25,19,9,16,28,20,10,5,0,4,8,15,22,
                      27,26,11,1,3,14,21,12,6,2,7,13};

    three2[0] = new Integer[]{11,6,1,5,10,12,2,0,19,20,13,7,3,4,9,18,24,25,26,
                      21,14,8,17,29,27,22,15,16,23,28};
    add(id);
    add(five[0]);
    add(three1[0]);
    add(three2[0]);

    // Iterations of degree-5 rotations:
    for (int i = 1; i < 4; i++) {
      five[i] = compose(five[0],five[i-1]);
      add(five[i]);
    }

    // Iterations of degree-3 rotations:
    three1[1] = compose(three1[0],three1[0]);
    add(three1[1]);
    three2[1] = compose(three2[0],three2[0]);
    add(three2[1]);

    // all compositions of a 5-rotation and a 3-rotation ...
    for (int i = 0; i < 4; i++) {
      for (int j = 0; j < 2; j++) {
        add(compose(five[i],three1[j]));
        add(compose(three1[j],five[i]));
        add(compose(five[i],three2[j]));
        add(compose(three2[j],five[i]));
      }
    }

    // all compositions of two 3-rotations...
    for (int i = 0; i < 2; i++) {
      for (int j = 0; j < 2; j++) {
        add(compose(three1[i],three2[j]));
        add(compose(three2[j],three1[i]));
        for (int k = 0; k < 4; k++) { //... and a 5-rotation mixed in
          add(compose(five[k],compose(three1[i],three2[j])));
          add(compose(five[k],compose(three2[j],three1[i])));
          add(compose(three1[i],compose(five[k],three2[j])));
          add(compose(three2[j],compose(five[k],three1[i])));
          add(compose(three1[i],compose(three2[j],five[k])));
          add(compose(three2[j],compose(three1[i],five[k])));
        }
      }
    }

    // all compositions of a 3-rotation surrounded by two 5-rotations:
    for (int i = 0; i < 4; i++) {
      for (int j = 0; j < 4; j++) {
        for (int k = 0; k < 2; k++) {
          add(compose(five[i],compose(three1[k],five[j])));
          add(compose(five[i],compose(three2[k],five[j])));
        }
      }
    }

    // Convert set of arraylists into an array of arrays and sort:
    int tcount = 0;
    for (ArrayList<Integer> a:trans) {
      tr[tcount] = a.toArray(tr[tcount]);
      tcount++;
    }
    Arrays.sort(tr, new Comparator<Object[]>(){
       @Override
       public int compare(Object[] a, Object[] b) {
         Integer[] a1 = (Integer[])a;
         Integer[] b1 = (Integer[])b;
         if (a1[0] != b1[0])
           return a1[0] - b1[0];
         else
           return a1[1] - b1[1];
       }
    });

    // Read the three sections as sets:
    Scanner in = new Scanner(System.in);
    BitSet[] sect = new BitSet[3];
    for (int i = 0; i < 3; i++) {
      int n = in.nextInt();
       sect[i] = new BitSet();
       for (int j = 0; j < n; j++) {
         sect[i].set(in.nextInt()-1);
       }
    }
    // which faces are missing from sect[0]?
    BitSet missing = (BitSet) sect[0].clone();
    missing.flip(0,30);

    for (int i = missing.nextSetBit(0); i != -1; i = missing.nextSetBit(i+1)) {
      // Find transformations that map 0 to i, then apply to sect[1]
      for (int j = 0; j < 2; j++) {
        Integer[] t = tr[2*i+j];
        Integer[] result = apply(sect[1],t);
        BitSet newset = new BitSet();
        for (Integer k:result) {
          newset.set(k);
        }
        if (!sect[0].intersects(newset)) {
          BitSet misssave = (BitSet)missing.clone(); // save missing set

          // Remove some faces from the "missing" set:
          missing.xor(newset);

          // Find transformations that map 0 to l, then apply to sect[2]
          for (int l = missing.nextSetBit(0) ; l != -1;
                       l = missing.nextSetBit(l+1)) {
            for (int p = 0; p < 2; p++) {
              Integer[] t2 = tr[2*l+p];
              Integer[] result2 = apply(sect[2],t2);
              BitSet newset2 = new BitSet();
              for (Integer r:result2) {
                newset2.set(r);
              }

              // see if transformed set equals the missing faces:
              if (newset2.equals(missing)) {
                System.out.println("Yes");
                System.exit(0);
              }
            }
          }
          missing = misssave; // restore old "missing" set
        }
      }
    }
    System.out.println("No");
  }

//////////////////

  public static Integer[] compose(Integer[] a, Integer[] b) {
    Integer[] ans = new Integer[30];
    for (int i = 0; i < 30; i++) {
      ans[i] = a[b[i]];
    }
    return ans;
  }

//////////////////

  public static Integer[] apply(BitSet a, Integer[] trans) {
    Integer[] ans = new Integer[a.cardinality()];
    int j = 0;
    for (int i = a.nextSetBit(0); i != -1; i = a.nextSetBit(i+1)) {
      ans[j++] = trans[i];
    }
    return ans;
  }

//////////////////

  public static boolean add(Integer[] a) {
    return trans.add(new ArrayList<Integer>(Arrays.asList(a)));
  }

//////////////////
// FOR DEBUGGING ONLY:

  public static void print(ArrayList<Integer> a) {
    for (int i = 0; i < 30; i++) {
      System.out.printf("%d ",a.get(i));
    }
    System.out.println();
  }

//////////////////
// FOR DEBUGGING ONLY:

  public static void print(Integer[] a) {
    for (int i = 0; i < 30; i++) {
      System.out.printf("%d ",a[i]);
    }
    System.out.println();
  }

//////////////////
// FOR DEBUGGING ONLY:

  public static void print(BitSet b) {
    for (int i = b.nextSetBit(0); i != -1; i = b.nextSetBit(i+1)) {
      System.out.print(i+" ");
    }
    System.out.println();
  }
}
