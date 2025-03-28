import java.util.*;

// A Horizontal "event" is the attempt to place string "num" in row "row"
// of board number "board" so that column "col" is included
class Hevent {
  int board,row,col;
  String num;
  int numhc; // hashcode of the string "num"

  public Hevent(int b,int r,int c,String s) {
    board = b; row = r; col = c; num = s; numhc = num.hashCode();
  }

  @Override
  public final boolean equals(Object h) {
    Hevent other = (Hevent) h;
    return (other.board == board) && (other.row == row) && (other.col == col)
      && (other.num.equals(num));
  }

  @Override
  // NO CLUE as to how good a hash code this is!
  public final int hashCode() {
    int ans = numhc;
    ans ^= row << 10;
    ans ^= col << 15;
    ans ^= board << 20;
    return ans;
  }
}

public class Numble {
  public static int r,c,t;
  public static String[][] board0,board1,board2,board3;
  public static int[] tiles;
  public static ArrayList<Integer> start;
  public static long best;
  public static HashSet<Hevent> hevent;

  public static void main(String[] args) {
    hevent = new HashSet<Hevent>();
    Scanner in = new Scanner(System.in);
    r = in.nextInt();
    c = in.nextInt();
    board0 = new String[r][c];
    board1 = new String[r][c];
    board2 = new String[c][r];
    board3 = new String[c][r];

    start = new ArrayList<Integer>();
    for (int i = 0; i < r; i++) {
      for (int j = 0; j < c; j++) {
        board0[i][j] = in.next();
        board1[i][c-j-1] = board0[i][j];
        board2[j][i] = board0[i][j];
        board3[j][r-i-1] = board0[i][j];
      }
    }
    t = in.nextInt();
    tiles = new int[t];
    for (int i = 0; i < t; i++) {
      tiles[i] = in.nextInt();
    }
    Arrays.sort(tiles);

    best = 0;
    // find all possible "starting points" (vacant next to occupied):
    for (int i = 0; i < r; i++) {
      for (int j = 0; j < c; j++) {
        if (isNum(board0[i][j])) continue;
        if (i > 0 && isNum(board0[i-1][j])) {
          start.add(i*c+j);
          continue;
        } else if (i < r-1 && isNum(board0[i+1][j])) {
          start.add(i*c+j);
          continue;
        } else if (j > 0 && isNum(board0[i][j-1])) {
          start.add(i*c+j);
          continue;
        } else if (j < c-1 && isNum(board0[i][j+1])) {
          start.add(i*c+j);
          continue;
        }
      }
    } 
 
    // for each starting point, for each of four orientations (row vs col;
    // right-to-left and left-to-right)
    for (Integer i: start) {
      for (int b = 0; b < 4; b++) {
        int r1,c1,row, col;
        String[][] board;
        if (b==0) {board = board0; r1 = r; c1 = c; row = i/c; col = i%c;}
        else if (b==1) {board = board1; r1 = r; c1 = c; row = i/c; col = c-i%c-1;}
        else if (b==2) {board = board2; r1 = c; c1 = r; row = i%c; col = i/c;}
        else           {board = board3; r1 = c; c1 = r; row = i%c; col = r-i/c-1;}
        long bst = solve(b,board,r1,c1,row,col,tiles);
        best = Math.max(best,bst);
      }
    }
    System.out.println(best);
  }


  ////////////////////////////////////////
  // All the hard work gets done here
  ////////////////////////////////////////
  public static long solve(int b, String[][] board, int r, int c, int row,
                           int col, int[] tiles) {
    if (c == 1) { // Only result is a column sum; use some other orientation
      return 0;
    }

    int besthz = 0;

    // Given that we have t tiles, how many different empty spaces in
    // this row are open and eligible to be filled, assuming that the set of 
    // filled spaces must contain (row,col)?
    // For instance, if we have three tiles and we are required to
    // fill column 6, then "- - - 2 - 1 - - 3 - - 5 -"
    //                      0 1 2 3 4 5 6 7 8 9 0 1 2
    //                          *   *   * *   *
    // columns 2,4,6,7, and 9 could be used to hold tiles.

    int count = 1; // for sure, (row,col) is empty
    ArrayList<Integer> open = new ArrayList<Integer>();
    open.add(col);

    // Move left and right from column "col", counting empty spaces
    int delta = 1;
    while (col-delta >= 0 && count < t) {
      if (!isNum(board[row][col-delta])) {
        open.add(col-delta);
        count++;
      }
      delta++;
    }
    delta = 1;
    int count2 = 1;
    while (col+delta < c && count2 < t) {
      if (!isNum(board[row][col+delta])) {
        open.add(col+delta);
        count2++;
      }
      delta++;
    }
    count += count2-1;
    Collections.sort(open);

  // MAIN LOOP: Try each subsequence of tiles up to size "count"
  // Use bitset representation of tile sets.
    int max = (int)Math.pow(2,t)-1;
    for (int i = 1; i <= max; i++) {
      int bits = Integer.bitCount(i); // How big is the set?
      if (bits > count) {
          continue; // set is too big to fit in available open spaces
      }

      int[] nums = new int[bits]; // Which tiles are in the set?
      String stringnums = "";
      int bc = 0; // counts tiles as we identify them for inclusion
      for (int j = 0; j < t && bc < bits; j++) {
        if (((1<<j) & i) > 0) {
          nums[bc++] = tiles[j];
          stringnums += tiles[j];
        }
      }

      // This subset of tiles might already have been attempted for this
      // board and this location--don't do the work again:
      Hevent h = new Hevent(b,row,col,stringnums);
      if (hevent.contains(h)) {
        continue;
      } else {
        hevent.add(h);
      }

      // Finally, time to start calculating. Locate "col" in the list
      // of open columns, then try placing nums at all possible places
      // that include col:
      int cloc = open.indexOf(col);

      // Special case: single digit and nothing to the left or right;
      // in this case, no horizontal contribution to score, but there
      // could still be a vertical contribution
      if (bc == 1 && (col==0 || (col > 0 && !isNum(board[row][col-1])))
         && (col==c-1 || (col < c-1 && !isNum(board[row][col+1])))) {

        // we know there must be a tile above or below (row,col):
        int vscore = vert(b,board,r,c,row,col,stringnums.charAt(0)-'0');

        besthz = Math.max(besthz,vscore);
        continue;
      }

      // There is at least one tile next to (row,col), so compute score.
      // Try every position where a set of length bc can fit (while
      // include column "col").
      // open[j] = starting location for tile placement (but the actual
      // digit string to be checked might begin to the left of this using
      // already-placed tiles)

      for (int j=Math.max(0,cloc-bc+1); j<=Math.min(cloc,open.size()-bc); j++) {

        // Build the horizontal number; remember double and triple multipliers
        int mult = 1;
        int adds = 0;

        // We may have added a tile to the immediate right of an already-
        // placed tile (from the input board); need to find the
        // beginning of the tile sequence, so "back up" to next empty space.

        int back = open.get(j)-1; // starting column we're looking for
        
        while (back >= 0) {
          if (!isNum(board[row][back])) {
            break;
          }
          back--;
        }
        back++;

        int cc = 0; // cc counts tiles in the set to be placed
        String horiz = "";
        int loc = back;
        while (loc < c) {
          // Check the board to see what's there...
          String be = board[row][loc];

          if (isNum(be)) { // is it a tile?
            horiz += be; // add it to the number
          } else if (cc < bc && be.equals("d")) { // is it "double" digit?
            horiz += ""+nums[cc]; // place a tile ...
            adds += nums[cc++]; // ...and remember the doubling
          } else if (cc < bc && be.equals("t")) { // is it "triple" digit?
            horiz += ""+nums[cc]; // place a tile ...
            adds += 2*nums[cc++]; // ...and remember the tripling
          } else if (cc < bc && be.equals("D")) { // is it "double score"?
            horiz += ""+nums[cc++]; // place a tile ...
            mult *= 2; // ...and remember the multiplier
          } else if (cc < bc && be.equals("T")) { // is it "triple score"?
            horiz += ""+nums[cc++]; // place a tile ...
            mult *= 3; // ...and remember the multiplier
          } else if (cc < bc) { // only other possibility is "-"
            horiz += ""+nums[cc++]; // place a tile
          } else { // all tiles have been placed; no more tiles to the right
            break;
          }
          loc++;
        }

        // Give up if tiles are not in order:
        if (horiz.length() > 1 && !inorder(horiz)) {
          continue;
        }

        // Give up if horizontal score not divisible by 3:
        int hz = sumdig(horiz);
        hz += adds;
        hz *= mult;
        if (horiz.length() > 1 && hz%3 != 0) {
          continue;
        }
  
        // Now we must look at all the vertical words that cross this
        // horizontal word at new tile placement locations:

        loc = back; // start over at the beginning
        for (int hp = 0; hp < horiz.length(); hp++) {
          // Only need to worry about cases when there are tiles
          // above and/or below a placed tile:
          if (open.contains(loc) && 
           ((row > 0 && isNum(board[row-1][loc])) ||
           (row < r-1 && isNum(board[row+1][loc])))) { 
            int vscore = vert(b,board,r,c,row,loc,horiz.charAt(hp)-'0');
            if (vscore > 0) {
              hz += vscore;
            } else { // something must have been wrong with the vertical word
              hz = 0;
              break;
            }
          }
          loc++;
        }
        besthz = Math.max(besthz,hz);
      } // Done with all horizontal placements of tile set i
    } // Done trying all subsets of tiles
      
    return besthz;
  }

  // See if a board entry already contains a number tile:
  public static boolean isNum(String be) {
    return "123456789".contains(be);
  }

   // See if a string of digits is in ascending or descending order:
   public static boolean inorder(String s) {
    char temp[] = s.toCharArray();
    Arrays.sort(temp);
    if (new String(temp).equals(s)) return true;
    char temp2[] = new char[temp.length];
    for (int i = 0; i < temp.length; i++)
      temp2[i] = temp[temp.length-i-1];
    if (new String(temp2).equals(s)) return true;
    return false;
  }

  // Sum of digits in a string of digits:
  public static int sumdig(String s) {
    int sum = 0;
    for (int i = 0; i < s.length(); i++) {
      sum += s.charAt(i)-'0';
    }
    return sum;
  }

  // Find the score of a vertical word consisting of one newly-placed
  // tile in (row,col).
  public static int vert(int b, String[][] board, int r, int c, int row, int col, int tile) {
    int mult = 1;
    int adds = 0;

    int back = row-1; // starting row we're looking for
    
    while (back >= 0) {
      if (!isNum(board[back][col])) {
        break;
      }
      back--;
    }
    back++;


    String vertical = "";

    int loc = back;
    int rc = 0;
    while (loc < r) {
      // Check the board to see what's there...
      String be = board[loc][col];

      if (isNum(be)) { // is it a tile?
        vertical += be; // add it to the number
      } else if (loc == row) {
          if (be.equals("d")) { // is it "double" digit?
          vertical += ""+tile; // place the tile ...
          adds += tile; // ...and remember the doubling
        } else if (be.equals("t")) { // is it "triple" digit?
          vertical += ""+tile; // place a tile ...
          adds += 2*tile; // ...and remember the tripling
        } else if (be.equals("D")) { // is it "double score"?
          vertical += ""+tile; // place a tile ...
          mult *= 2; // ...and remember the multiplier
        } else if (be.equals("T")) { // is it "triple score"?
          vertical += ""+tile; // place a tile ...
          mult *= 3; // ...and remember the multiplier
        } else { // only other possibility is "-"
          vertical += ""+tile; // place a tile
        }
      } else break;
      loc++;
    }

    // Fail if digits not in order:
    if (vertical.length() > 1 && !inorder(vertical)) {
      return 0;
    }

    int vt = sumdig(vertical);
    vt += adds;
    vt *= mult;

    // Fail if not a multiple of 3:
    if (vertical.length() > 1 && vt%3 != 0) {
      return 0;
    }
    return vt;
  }
}
