// Problem: Weighted Window Sums
// UCF Local Contest 2023: Qualification Round
//
// Yiu Yu (Raymond) Ho

import java.io.*;
import java.time.*;
import java.util.*;

public class Weighted {

  // Data object to store the weighted sum of a window at a starting index.
  // The size of the window is omitted because it is a constant for each test case.
  private static class WindowInfo implements Comparable<WindowInfo> {
    public int index;
    public long weightedSum;

    public WindowInfo(int indexInput, long weightedSumInput) {
      index = indexInput;
      weightedSum = weightedSumInput;
    }

    @Override
    public int compareTo(WindowInfo other) {
      int c = Long.compare(weightedSum, other.weightedSum);
      if (c != 0) {
        return c;
      }

      return (index - other.index);
    }
  }

  // The entry point of the solution.
  // This API is designed to make it easier to compare the results with reference data.
  // In some cases, buffering the output in a single `String` have better execution time compared
  // to printing the lines one by one.
  public static ArrayList<String> getOutput(ArrayList<String> input) {
    ArrayList<Integer> nAndK = parseIntList(input.get(0));
    int n = nAndK.get(0);
    int k = nAndK.get(1);

    // `v` is the input sequence.
    // Note that `v[0]` is not used.
    long[] v = new long[n + 1];
    for (int i = 1; i <= n; ++i) {
      v[i] = Long.parseLong(input.get(i));
    }

    // Prefix sum of `v`.
    // sum[i] = v[1] + v[2] + ... + v[i]
    long[] sum = new long[n + 1];
    for (int i = 1; i <= n; ++i) {
      sum[i] = sum[i - 1] + v[i];
    }

    ArrayList<WindowInfo> windows = new ArrayList<>();

    long weightedSum = 0;

    // Calculate weighted sum for the window at starting index `1`.
    for (int i = 1; i <= k; ++i) {
      weightedSum += i * v[i];
    }

    windows.add(new WindowInfo(/*index=*/1, weightedSum));
    for (int i = 1; i + k <= n; ++i) {
      // Compute the weighted sum of the window at starting index `i + 1` using the weighted
      // sum of the window at starting index `i`.
      // (1 * v[i] + 2 * v[i + 1] + ... + k * v[i + k - 1])
      // - (v[i] + v[i + 1] + ... + v[i + k - 1])
      // + k * v[i + k]
      // = 1 * v[i + 1] + ... + (k - 1) * v[i + k - 1] + k * v[i + k]

      weightedSum = weightedSum - (sum[i + k - 1] - sum[i - 1]) + k * v[i + k];
      windows.add(new WindowInfo(i + 1, weightedSum));
    }

    Collections.sort(windows);
    ArrayList<String> output = new ArrayList<>();
    for (WindowInfo Weighted : windows) {
      output.add(Weighted.index + " " + Weighted.weightedSum);
    }

    return output;
  }

  /**
   * Parses the input `string` of space separated integers and returns the result as an
   * ArrayList of Integer(s).
   */
  private static ArrayList<Integer> parseIntList(String string) {
    StringTokenizer tokens = new StringTokenizer(string);

    ArrayList<Integer> result = new ArrayList<>();
    while (tokens.hasMoreTokens()) {
      result.add(Integer.parseInt(tokens.nextToken()));
    }

    return result;
  }

  // Returns an `ArrayList<String>` containing all data from `in`.
  private static ArrayList<String> readInput(BufferedReader in) throws IOException {
    ArrayList<String> input = new ArrayList<>();

    String line = in.readLine();
    while (line != null) {
      input.add(line);
      line = in.readLine();
    }

    return input;
  }

  public static void main(String[] args) throws IOException {
    Instant startTime = Instant.now();

    BufferedReader in = new BufferedReader(new InputStreamReader(System.in));

    ArrayList<String> input = readInput(in);
    ArrayList<String> output = getOutput(input);

    System.out.println(String.join("\n", output));

    Instant endTime = Instant.now();
    System.err.println("Execution time = " + Duration.between(startTime, endTime));
  }
}
