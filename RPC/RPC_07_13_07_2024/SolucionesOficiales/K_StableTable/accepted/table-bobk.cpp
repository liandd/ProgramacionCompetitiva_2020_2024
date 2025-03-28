#include <iostream>
#include <vector>
#include <set>
#include <queue>

using namespace std;

#define REPI(ctr,start,limit) for (uint32_t ctr=(start);(ctr)<(limit);(ctr)++)

const uint32_t
    MAX_SIZE = 100;

int main() {
    int32_t
        block[MAX_SIZE][MAX_SIZE],
        largest = 0,
        dist[MAX_SIZE*MAX_SIZE+1],
        dist2[MAX_SIZE*MAX_SIZE+1],
        upDist[MAX_SIZE*MAX_SIZE+1],
        top[2],
        h,w;
    vector<set<uint32_t> >
        upList,downList;
    queue<uint32_t>
        q;

    cin >> h >> w;

    REPI(r,0,h)
        REPI(c,0,w) {
            cin >> block[r][c];

            if (block[r][c] > largest)
                largest = block[r][c];
        }

    upList.resize(largest+1);
    downList.resize(largest+1);

    REPI(r,0,h-1)
        REPI(c,0,w)
            if (block[r][c] != block[r+1][c]) {
                downList[block[r][c]].emplace(block[r+1][c]);
                upList[block[r+1][c]].emplace(block[r][c]);
            }

    REPI(c,0,w) {
        downList[block[h-1][c]].emplace(0);
        upList[0].emplace(block[h-1][c]);
    }

    top[0] = top[1] = -1;
    REPI(i,0,largest+1)
        dist[i] = dist2[i] = upDist[i] = -1;

    REPI(c,0,w)
        if (top[0] == -1)
            top[0] = block[0][c];
        else if (top[0] != block[0][c])
            top[1] = block[0][c];

#ifdef DEBUG
    cout << top[0] << ' ' << top[1] << endl;
    REPI(i,0,largest+1) {
        for (unsigned int it : downList[i])
            cout << it << ' ';
        cout << endl;
    }
    cout << "---" << endl;
    REPI(i,0,largest+1) {
        for (unsigned int it : upList[i])
            cout << it << ' ';
        cout << endl;
    }
#endif

    q.push(top[0]);
    dist[top[0]] = 0;

    while (!q.empty()) {
        uint32_t
            piece = q.front();

        q.pop();

        for (auto it=downList[piece].begin();it!=downList[piece].end();it++)
            if (dist[*it] == -1) {
                dist[*it] = dist[piece] + 1;
                q.push(*it);
            }
    }

    if (top[1] == -1) {
        cout << dist[0] << endl;
        return 0;
    }

    q.push(top[1]);
    dist2[top[1]] = 0;

    while (!q.empty()) {
        uint32_t
            piece = q.front();

        q.pop();

        for (auto it=downList[piece].begin();it!=downList[piece].end();it++)
            if (dist2[*it] == -1) {
                dist2[*it] = dist2[piece] + 1;
                q.push(*it);
            }
    }

    q.push(0);
    upDist[0] = 0;

    while (!q.empty()) {
        uint32_t
            piece = q.front();

        q.pop();

        for (auto it=upList[piece].begin();it!=upList[piece].end();it++)
            if (upDist[*it] == -1) {
                upDist[*it] = upDist[piece] + 1;
                q.push(*it);
            }
    }

    uint32_t
        best = 999999;

    REPI(i,0,largest+1)
        if (dist[i] != -1 && dist2[i] != -1 && dist[i] + dist2[i] + upDist[i] < best)
            best = dist[i] + dist2[i] + upDist[i];

#ifdef DEBUG
    REPI(i,0,largest+1)
        cout << dist[i] << ' ';
    cout << endl;

    REPI(i,0,largest+1)
        cout << dist2[i] << ' ';
    cout << endl;

    REPI(i,0,largest+1)
        cout << upDist[i] << ' ';
    cout << endl;
#endif

    cout << best << endl;

    return 0;
}
