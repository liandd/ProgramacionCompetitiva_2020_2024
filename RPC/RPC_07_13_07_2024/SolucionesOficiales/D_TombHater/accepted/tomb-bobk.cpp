#include <iostream>
#include <string>

using namespace std;

const int
    QCAP = 1000000,
    DSIZE = 18750000,
    SIZE = 50;

int
    qCount,qTail,qHead,
    k,
    queue[QCAP],
    dist[DSIZE];

char
    grid[SIZE][SIZE];
string
    glyphs[SIZE];

void enqueue(int dir,int row,int col,int word,int pos) {

    if (qCount == QCAP) {
        cerr << "Queue full" << endl;
        return;
    }

    qCount++;

    queue[qTail] = pos + SIZE * (word + SIZE * (col + SIZE * (row + SIZE * dir)));

    qTail = (qTail + 1) % QCAP;
}

int dequeue() {

    qCount--;

    qHead = (qHead + 1) % QCAP;

    return queue[qHead];
}

void check(int dir,int row,int col,int word,int pos,int cost) {
    char
        symbol = grid[row][col];
    int
        idx = SIZE * (col + SIZE * (row + SIZE * dir));

    if (pos == glyphs[word].length())
        for (int i=0;i<k;i++) {
            int idx2 = SIZE * (i + idx);
            if (symbol == glyphs[i][0] && dist[idx2] == -1) {
                dist[idx2] = cost + 1;
                enqueue(dir,row,col,i,0);
            }
        }
    else {
        int idx2 = pos + SIZE * (word + idx);
        if (symbol == glyphs[word][pos] && dist[idx2] == -1) {
            dist[idx2] = cost + 1;
            enqueue(dir, row, col, word, pos);
        }
    }
}

int main() {
    int
        m,n;

    for (int & val : dist)
        val = -1;

    cin >> m >> n >> k;

    for (int r = 0; r< m; r++)
        for (int c = 0; c< n; c++)
            cin >> grid[r][c];

    for (int i=0;i<k;i++)
        cin >> glyphs[i];

    qHead = QCAP - 1;
    qTail = 0;
    qCount = 0;

    for (int i = 0; i< n; i++)
        for (int j=0;j<k;j++)
            if (grid[0][i] == glyphs[j][0]) {
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
        cout << "impossible" << endl;
    else
        cout << best << endl;

    return 0;
}
