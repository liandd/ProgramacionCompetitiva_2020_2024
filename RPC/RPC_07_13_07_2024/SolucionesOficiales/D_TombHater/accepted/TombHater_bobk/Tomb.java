import java.util.Scanner;

public class Tomb {

    private final static int
        QCAP = 1000000,
        DSIZE = 18750000,
        SIZE = 50;

    private static int
        qCount;
    private static int qTail;
    private static int qHead;
    private static int k;
    private static int[]
        dist,
        queue;

    private static char[][]
        grid;

    private static String[]
        glyphs;

    private static void enqueue(int dir,int row,int col,int word,int pos) {

        if (qCount == QCAP) {
            System.err.println("Queue full");
            return;
        }

        qCount++;

        queue[qTail] = pos + SIZE * (word + SIZE * (col + SIZE * (row + SIZE * dir)));

        qTail = (qTail + 1) % QCAP;
    }

    private static int dequeue() {

        qCount--;

        qHead = (qHead + 1) % QCAP;

        return queue[qHead];
    }

    private static void check(int dir,int row,int col,int word,int pos,int cost) {
        char
            symbol = grid[row][col];
        int
            idx = SIZE * (col + SIZE * (row + SIZE * dir));

        if (pos == glyphs[word].length())
            for (int i=0;i<k;i++) {
                int idx2 = SIZE * (i + idx);
                if (symbol == glyphs[i].charAt(0) && dist[idx2] == -1) {
                    dist[idx2] = cost + 1;
                    enqueue(dir,row,col,i,0);
                }
            }
        else {
            int idx2 = pos + SIZE * (word + idx);
            if (symbol == glyphs[word].charAt(pos) && dist[idx2] == -1) {
                dist[idx2] = cost + 1;
                enqueue(dir, row, col, word, pos);
            }
        }
    }

    public static void main(String[] args) {
        Scanner
            in = new Scanner(System.in);

        dist = new int[DSIZE];
        for (int i=0;i<DSIZE;i++)
            dist[i] = -1;

        int m = in.nextInt();
        int n = in.nextInt();
        k = in.nextInt();

        grid = new char[m][n];
        glyphs = new String[k];

        for (int r = 0; r< m; r++)
            for (int c = 0; c< n; c++)
                grid[r][c] = in.next().charAt(0);

        for (int i=0;i<k;i++)
            glyphs[i] = in.next();

        queue = new int[QCAP];
        qHead = QCAP - 1;
        qTail = 0;
        qCount = 0;

        for (int i = 0; i< n; i++)
            for (int j=0;j<k;j++)
                if (grid[0][i] == glyphs[j].charAt(0)) {
                    dist[SIZE * (j + SIZE * (i + SIZE * SIZE))] = 1;
                    enqueue(1, 0, i, j, 0);
                }

        while (qCount > 0) {
            int cell = dequeue();
            int cell2 = cell;
            int pos = cell % SIZE;
            cell /= SIZE;
            int word = cell % SIZE;
            cell /= SIZE;
            int col = cell % SIZE;
            cell /= SIZE;
            int row = cell % SIZE;
            int dir = cell / SIZE;

            if (dir != 2 && col > 0)
                check(0, row, col - 1, word, pos + 1, dist[cell2]);
            if (row < m - 1)
                check(1, row + 1, col, word, pos + 1, dist[cell2]);
            if (dir != 0 && col < n - 1)
                check(2, row, col + 1, word, pos + 1, dist[cell2]);
        }

        int best = 99999;
        for (int i=0;i<n;i++)
            for(int j=0;j<k;j++)
                for(int d=0;d<3;d++) {
                    int val = dist[glyphs[j].length() - 1 + SIZE * (j + SIZE * (i + SIZE * (m - 1 + SIZE * d)))];
                    if (-1 < val && val < best)
                        best = val;
                }

        if (best == 99999)
            System.out.println("impossible");
        else
            System.out.println(best);
    }
}
