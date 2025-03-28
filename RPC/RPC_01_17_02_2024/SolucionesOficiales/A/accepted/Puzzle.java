import java.util.Scanner;

public class Puzzle {
    public static final String DIRS = "NESW";
    public static final int[] DR = {1,0,-1,0};
    public static final int[] DC = {0,1,0,-1};
    public static final int QSIZE = 1000000;

    public static void main(String[] args) {
        Scanner
            in = new Scanner(System.in);
        int
            c, r, e,
            c1, r1, c2, r2, d1, d2,
            orient,
            nw, wr, wc,
            qc = 0, qh = -1, qt = 0,
            curLoc, newLoc,
            tmp,
            newBumps, newDist,
            c1new, r1new, c2new, r2new;
        int[]
            dist,
            bumps,
            q = new int[QSIZE];
        boolean[][]
            hasWall;

        c = in.nextInt();
        r = in.nextInt() + 1;
        e = in.nextInt() - 1;

        c1 = in.nextInt() - 1;
        r1 = in.nextInt();
        d1 = DIRS.indexOf(in.next().charAt(0));

        c2 = in.nextInt() - 1;
        r2 = in.nextInt();
        d2 = DIRS.indexOf(in.next().charAt(0));

        orient = (4 + d2 - d1) % 4;

        hasWall = new boolean[r * c][4];
        for (int i=0;i<r*c;i++)
            hasWall[i][0] = hasWall[i][1] = hasWall[i][2] = hasWall[i][3] = false;

        nw = in.nextInt();
        for (int i=0;i<nw;i++) {
            wc = in.nextInt() - 1;
            wr = in.nextInt();
            hasWall[wc + c * wr][0] = hasWall[wc + c * (wr + 1)][2] = true;
        }

        nw = in.nextInt();
        for (int i=0;i<nw;i++) {
            wc = in.nextInt() - 1;
            wr = in.nextInt();
            hasWall[wc + c * wr][1] = hasWall[wc + c * wr + 1][3] = true;
        }

        for (int i=0;i<c;i++) {
            if (i != e)
                hasWall[i + c][2] = true;
            hasWall[i + c * (r - 1)][0] = true;
        }

        for (int i=1;i<r;i++)
            hasWall[c * i][3] = hasWall[c * (i + 1) - 1][1] = true;

        dist = new int[c * r * c * r];
        bumps = new int[c * r * c * r];
        for (int i=0;i<c * r * c * r;i++) {
            dist[i] = -1;
            bumps[i] = 2147483647;
        }

        curLoc = c1 + c * (r1 + r * (c2 + c * r2));
        dist[curLoc] = 0;
        bumps[curLoc] = 0;

        q[qt] = curLoc;
        qt = (qt + 1) % QSIZE;
        qc++;

        while (qc > 0) {
            qh = (qh + 1) % QSIZE;
            curLoc = q[qh];
            qc--;

            tmp = curLoc;
            c1 = tmp % c;
            tmp /= c;
            r1 = tmp % r;
            tmp /= r;
            c2 = tmp % c;
            r2 = tmp / c;

            for (d1=0;d1<4;d1++) {
                d2 = (d1 + orient) % 4;

                newBumps = 0;

                c1new = c1;
                r1new = r1;

                if (r1 > 0) {
                    if (hasWall[c1 + c * r1][d1])
                        newBumps++;
                    else {
                        c1new += DC[d1];
                        r1new += DR[d1];
                    }
                }

                c2new = c2;
                r2new = r2;

                if (r2 > 0) {
                    if (hasWall[c2 + c * r2][d2])
                        newBumps++;
                    else {
                        c2new += DC[d2];
                        r2new += DR[d2];
                    }
                }

                if (c1new != c2new || r1new != r2new || r1new == 0) {
                    if (c1new == c2 && r1new == r2 && c2new == c1 && r2new == r1)
                        continue;

                    newLoc = c1new + c * (r1new + r * (c2new + c * r2new));
                    newDist = dist[curLoc] + 1;
                    newBumps += bumps[curLoc];

                    if (dist[newLoc] == -1) {
                        dist[newLoc] = newDist;
                        bumps[newLoc] = newBumps;

                        q[qt] = newLoc;
                        qt = (qt + 1) % QSIZE;
                        qc++;
                    } else if (dist[newLoc] == newDist && bumps[newLoc] > newBumps)
                        bumps[newLoc] = newBumps;
                }
            }
        }

        System.out.println(dist[e + r * c * e] + " " + bumps[e + r * c * e]);
    }
}
