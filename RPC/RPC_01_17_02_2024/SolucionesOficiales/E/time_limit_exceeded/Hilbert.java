import java.io.*;
import java.util.*;

public class Hilbert {

    static boolean[][] leftBlocked;
    static boolean[][] downBlocked;

    static void buildMaze(int nCurveIterations) {
        if (nCurveIterations >= 13) {
            // We are not going to be able to construct the adjacency information.
            // I could implement the arrays in such a way that I do not get index
            // out of bounds, but these cases will certainly time out anyway. So
            // to make this compatible with verifyproblem, spin for a while to
            // prevent getting a memory limit exceeded.
            long start = System.currentTimeMillis();
            long now = System.currentTimeMillis();
            while (now - start < 60 * 1000) {
                now = System.currentTimeMillis();
            }
        }
        // Note for nCurveIterations > 30 this will hit overflow. These cases
        // would certainly time out anyway with this approach, so do not worry
        // about it.
        int width = 2;
        for (int i = 1; i < nCurveIterations; i++) {
            width *= 2;
        }
        leftBlocked = new boolean[width][width];
        downBlocked = new boolean[width][width];
        StringBuilder currSb = new StringBuilder("A");
        String aStr = "LBFRAFARFBL";
        String bStr = "RAFLBFBLFAR";
        for (int i = 0; i < nCurveIterations; i++) {
            StringBuilder nextSb = new StringBuilder();
            for (int j=0; j<currSb.length(); j++) {
                char currChar = currSb.charAt(j);
                if (currChar == 'L' || currChar == 'R' || currChar == 'F') {
                    nextSb.append(currChar);
                } else if (currChar == 'A') {
                    nextSb.append(aStr);
                } else if (currChar == 'B') {
                    nextSb.append(bStr);
                }
            }
            currSb = nextSb;
        }
        int x = 0;
        int y = 0;
        // Use dx and dy to track the direction we are facing.
        int dx = 1;
        int dy = 0;
        for (int i=0; i < currSb.length(); i++) {
            char ch = currSb.charAt(i);
            if (ch == 'A' || ch == 'B') {
                continue;
            }
            if (ch == 'L') {
                // Turn left.
                int ndx = -dy;
                int ndy = dx;
                dx = ndx;
                dy = ndy;
            }
            if (ch == 'R') {
                // Turn right.
                int ndx = dy;
                int ndy = -dx;
                dx = ndx;
                dy = ndy;
            }
            if (ch == 'F') {
                if (dx == 1) {
                    downBlocked[x][y] = true;
                } else if (dx == -1) {
                    downBlocked[x - 1][y] = true;
                } else if (dy == 1) {
                    leftBlocked[x][y] = true;
                } else if (dy == -1) {
                    leftBlocked[x][y-1] = true;
                }
                // Go forwards.
                x += dx;
                y += dy;
            }
        }
    }

    static boolean isOutside(long width, long x, long y) {
        return (x<0 || y<0 || x >= width - 1 || y >= width - 1);
    }

    static boolean isOutside(long x, long y) {
        int width = leftBlocked.length;
        return isOutside(width, x ,y);
    }

    static long outsideDistance(long x1, long y1, long x2, long y2) {
        int width = leftBlocked.length;
        return outsideDistance(width, x1, y1, x2, y2);
    }

    static long outsideDistance(long width, long x1, long y1, long x2, long y2) {
        long dx = x2 - x1;
        long dy = y2 - y1;
        if (dx < 0) {
            dx *= -1;
        }
        if (dy < 0) {
            dy *= -1;
        }

        if (0 <= x1 && x1 <= width - 2 && 0 <= x2 && x2 <= width - 2) {
            long dx1 = x1 + 1 + x2 + 1;
            long dx2 = (width - 1 - x1) + (width - 1 - x2);
            if ((y1 < 0 || y2 < 0) && (y1 > width - 2 || y2 > width - 2)) {
                if (dx1 < dx2) {
                    dx = dx1;
                } else {
                    dx = dx2;
                }
            }
        }
        if (0 <= y1 && y1 <= width - 2 && 0 <= y2 && y2 <= width - 2) {
            long dy1 = y1 + 1 + y2 + 1;
            long dy2 = (width - 1 - y1) + (width - 1 - y2);
            if ((x1 < 0 || x2 < 0) && (x1 > width - 2 || x2 > width - 2)) {
                if (dy1 < dy2) {
                    dy = dy1;
                } else {
                    dy = dy2;
                }
            }
        }
        return dx + dy;
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int numCases = Integer.parseInt(br.readLine());
        for (int test = 0; test < numCases; test++) {
            String[] s = br.readLine().split(" ");
            int nCurveIterations = Integer.parseInt(s[0]);
            long x1 = Long.parseLong(s[1]);
            long y1 = Long.parseLong(s[2]);
            long x2 = Long.parseLong(s[3]);
            long y2 = Long.parseLong(s[4]);
            long longWidth = 2;
            for (int i=1; i < nCurveIterations; i++) {
                longWidth *= 2L;
            }
            if (isOutside(longWidth, x1, y1)) {
                if (isOutside(longWidth, x2, y2)) {
                    System.out.println(outsideDistance(longWidth, x1, y1, x2, y2));
                    continue;
                } else {
                    // Switch p1 and p2.
                    long tmp = x1;
                    x1 = x2;
                    x2 = tmp;
                    tmp = y1;
                    y1 = y2;
                    y2 = tmp;
                }
            }
            buildMaze(nCurveIterations);
            int width = leftBlocked.length;
            // Do a BFS from (x1,y1) until we reach (x2,y2)
            LinkedList<Integer> xq = new LinkedList<>();
            LinkedList<Integer> yq = new LinkedList<>();
            // Offset vis by 1 to allow exiting to x=-1 and y=-1.
            boolean[][] vis = new boolean[width + 1][width + 1];
            int[] dx = new int[]{1,-1,0,0};
            int[] dy = new int[]{0,0,1,-1};
            xq.offer((int)x1);
            yq.offer((int)y1);
            xq.offer(null);
            yq.offer(null);
            vis[(int)x1 + 1][(int)y1 + 1] = true;
            int distance = 0;
            while (xq.size() > 0) {
                Integer cx = xq.poll();
                Integer cy = yq.poll();
                if (cx == null) {
                    distance++;
                    xq.offer(null);
                    yq.offer(null);
                    continue;
                }
                if (cx == x2 && cy == y2) {
                    break;
                }
                if (isOutside(cx, cy) && isOutside(x2, y2)) {
                    distance += outsideDistance(cx, cy, x2, y2);
                    break;
                }
                for (int i = 0; i < 4; i++) {
                    int nx = cx + dx[i];
                    int ny = cy + dy[i];
                    if (nx < -1 || ny < -1 || nx >= width || ny >= width || vis[nx + 1][ny + 1]) {
                        continue;
                    }
                    if (dx[i] == 1 && ny >= 0 && leftBlocked[nx][ny]) {
                        continue;
                    }
                    if (dx[i] == -1 && cy >= 0 && leftBlocked[cx][cy]) {
                        continue;
                    }
                    if (dy[i] == 1 && nx >= 0 && downBlocked[nx][ny]) {
                        continue;
                    }
                    if (dy[i] == -1 && cx >= 0 && downBlocked[cx][cy]) {
                        continue;
                    }
                    xq.offer(nx);
                    yq.offer(ny);
                    vis[nx + 1][ny + 1] = true;
                }
            }
            System.out.println(distance);
        }

    }
}