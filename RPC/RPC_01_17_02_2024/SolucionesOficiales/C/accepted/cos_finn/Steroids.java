import java.io.*;
import java.util.*;

/**
 * Score the runs and pairs just following the rules. To score the fifteens,
 * Generate all possible distinct partitions of 15 and use binomial coefficients
 * to efficiently count the number of ways to get cards whose values sum to 15.
 *
 * @author Finn Lidbetter
 */

public class Steroids {
    static int MAX_N = 100;
    static long[][] combs = new long[MAX_N + 1][MAX_N + 1];
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        for (int i=0; i < MAX_N + 1; i++) {
            combs[i][0] = 1;
            combs[i][i] = 1;
        }
        for (int i=1; i < MAX_N + 1; i++) {
            for (int j=1; j<i; j++) {
                combs[i][j] = combs[i-1][j-1] + combs[i-1][j];
            }
        }
        int n = sc.nextInt();
        int[] cardCounts = new int[14];
        int[] valueCounts = new int[11];
        String[] s = new String[n];
        for (int i=0; i<n; i++) {
            s[i] = sc.next();
        }
        for (int i=0; i<n; i++) {
            if (s[i].equals("A")) {
                cardCounts[1]++;
                valueCounts[1]++;
            } else if (s[i].equals("T")) {
                cardCounts[10]++;
                valueCounts[10]++;
            } else if (s[i].equals("J")) {
                cardCounts[11]++;
                valueCounts[10]++;
            } else if (s[i].equals("Q")) {
                cardCounts[12]++;
                valueCounts[10]++;
            } else if (s[i].equals("K")) {
                cardCounts[13]++;
                valueCounts[10]++;
            } else {
                int value = Integer.parseInt(s[i]);
                cardCounts[value]++;
                valueCounts[value]++;
            }
        }
        long pairsScore = countPairs(cardCounts);
        long fifteenScore = countFifteens(valueCounts);
        long runsScore = countRuns(cardCounts);
        //System.err.println("pairs score: " + pairsScore);
        //System.err.println("fifteens score: " + fifteenScore);
        //System.err.println("runs score: " + runsScore);
        System.out.println(pairsScore + fifteenScore + runsScore);
    }
    
    static long countPairs(int[] cardCounts) {
        long total = 0;
        for (int i=0; i<14; i++) {
            total += cardCounts[i] * (cardCounts[i] - 1);
        }
        return total;
    }
    
    static long countRuns(int[] cardCounts) {
        long total = 0;
        int currRunLength = 0;
        for (int i=1; i<14; i++) {
            if (cardCounts[i]>0) {
                currRunLength += 1;
            } else if (cardCounts[i] == 0) {
                if (currRunLength >= 3) {
                    long prod = 1;
                    for (int j=currRunLength - 1; j>=0; j--) {
                        prod *= (long)cardCounts[i-1-j];
                    }
                    total += currRunLength * prod;
                }
                currRunLength = 0;
            }
        }
        if (currRunLength >= 3) {
            long prod = 1;
            for (int j=currRunLength - 1; j>=0; j--) {
                prod *= (long)cardCounts[cardCounts.length - 1 -j];
            }
            total += currRunLength * prod;
        }
        return total;
    }

    static int[] nextPartition(int[] curr, int target) {
        if (curr.length == target) {
            return null;
        }
        for (int i=curr.length-2; i>=0; i--) {
            int total = 0;
            int[] candidate = new int[curr.length];
            for (int j=0; j<i; j++) {
                candidate[j] = curr[j];
                total += candidate[j];
            }
            candidate[i] = curr[i] + 1;
            total += candidate[i];
            for (int j=i+1; j<curr.length - 1; j++) {
                candidate[j] = candidate[i];
                total += candidate[j];
            }
            candidate[curr.length-1] = target - total;
            boolean valid = true;
            for (int j=1; j<curr.length; j++) {
                if (candidate[j]<candidate[j-1]) {
                    valid = false;
                    break;
                }
            }
            if (valid)
                return candidate;
        }
        int[] candidate = new int[curr.length+1];
        for (int i=0; i<curr.length; i++) {
            candidate[i] = 1;
        }
        candidate[curr.length] = target - curr.length;
        return candidate;
    }

    static long countFifteens(int[] valueCounts) {
        int[] currPartition = new int[]{15};
        long total = 0;
        while (currPartition != null) {
            int[] multiplicities = new int[11];
            boolean valid = true;
            for (int i: currPartition) {
                if (i>10) {
                    valid = false;
                    break;
                }
                multiplicities[i]++;
                if (multiplicities[i] > valueCounts[i]) {
                    valid = false;
                    break;
                }
            }
            if (valid) {
                long partitionTotal = 1;
                for (int value=1; value<=10; value++) {
                    if (multiplicities[value] > 0) {
                        partitionTotal *= combs[valueCounts[value]][multiplicities[value]];
                    }
                }
                total += partitionTotal;
            }
            currPartition = nextPartition(currPartition, 15);
        }
        return 2*total;
    }
}
