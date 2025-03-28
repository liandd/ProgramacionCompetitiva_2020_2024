import java.util.*;
import java.io.*;

public class protect {
    // Let's be honest. you didn't do as much competitive programming
    // over the summer as you told yourself you would do, and hence forgot
    // how to code simple algorithms. But based on the vibes of this problem,
    // and your knowledge that you would like to have an automaton that keeps
    // you as deep in the trie as you can be, luckily you are still good at
    // transcribing hackpack.
    static final int ALPHA = 26;
    static class AhoCorasick {
        int nodeCount;
        int[][] transition, children;
        int[] term, leaf;
        ArrayDeque<Integer> q;
        AhoCorasick() {}
        AhoCorasick(String[] strs) {
            int maxNodes = 1;
            for (String s : strs) maxNodes += (int) s.length();
            children = new int[ALPHA][maxNodes];
            leaf = new int[maxNodes];
            nodeCount = 1;
            for (String s : strs) {
                int node = 0;
                for (char ch : s.toCharArray()) {
                    int c = ch - 'a';
                    if (children[c][node] == 0)
                        children[c][node] = nodeCount++;
                    node = children[c][node];
                }
                leaf[node]++;
            }
            transition = new int[ALPHA][nodeCount];
            term = new int[nodeCount];
            q = new ArrayDeque<>();
            q.add(0);
            q.add(0);
            while (q.size() > 0) {
                int node = q.poll();
                int suffLink = q.poll();
                term[node] = leaf[node] + term[suffLink];
                for (int ch = 0; ch < ALPHA; ++ch) {
                    if (children[ch][node] != 0) {
                        transition[ch][node] = children[ch][node];
                        q.add(children[ch][node]);
                        q.add(node == 0 ? 0 : transition[ch][suffLink]);
                    } else {
                        transition[ch][node] = transition[ch][suffLink];
                    }
                }
            }
        }
    }

    static final long MOD = 1_000_000_007;
    static final int K = 24; // log_2(10^7)

    static long[][] mult(long[][] a, long[][] b) {
        long[][] out = new long[a.length][b[0].length];
        for (int i = 0; i < a.length; ++i) {
            for (int j = 0; j < b[0].length; ++j) {
                for (int k = 0; k < a[0].length; ++k) {
                    out[i][j] += a[i][k] * b[k][j];
                    out[i][j] %= MOD;
                }
            }
        }
        return out;
    }

    static long[][] ident(int n) {
        long[][] out = new long[n][n];
        for (int i = 0; i < n; ++i) out[i][i] = 1;
        return out;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int len = sc.nextInt();
        String a = sc.next(), b = sc.next();

        // Run Aho on our two strings
        String[] strs = {a, b};
        AhoCorasick aho = new AhoCorasick(strs);

        int n = aho.nodeCount;

        // Keep list of our 1 or 2 terminal states
        ArrayDeque<Integer> terms = new ArrayDeque<>();
        for (int i = 0; i < n; ++i) {
            if (aho.term[i] == 0) continue;

            terms.add(i);
            // If we ever reach a terminal state, might as well stay here
            // Loop all transitions back into ourselves
            for (int x = 0; x < ALPHA; ++x) aho.transition[x][i] = i;
        }

        // Create a matrix in which trans[i][j] tells us in how many ways we can
        // go from state i to state j by appending one letter to our string
        long[][] trans = new long[n][n];
        for (int i = 0; i < n; ++i) {
            for (int x = 0; x < ALPHA; ++x) {
                int j = aho.transition[x][i];
                trans[i][j] += 1;
            }
        }

        // Grab all powers of two of our transition matrix
        long[][][] pws = new long[K][][];
        pws[0] = trans;
        for (int kk = 1; kk < K; ++kk) {
            pws[kk] = mult(pws[kk - 1], pws[kk - 1]);
        }

        // Start with an empty string (1 way to reach root of trie/automaton)
        long[][] start = new long[1][n];
        start[0][0] = 1;

        // Transition exactly len times (append len letters)
        long[][] square = ident(n);
        for (int kk = 0; kk < K; ++kk) {
            if ((len & (1 << kk)) > 0) square = mult(square, pws[kk]);
        }

        long[][] end = mult(start, square);

        // Add up ways to reach our 1 or 2 terminal states
        long out = 0;
        for (int i : terms) {
            out += end[0][i];
            out %= MOD;
        }

        System.out.println(out);
    }
}
