#include <iostream>

using namespace std;

#define REPI(ctr,start,limit) for (uint32_t ctr=(start);(ctr)<(limit);(ctr)++)

const uint32_t
    MAX_BASES = 50000;

const char
    BASES[] = "ATGC";

uint32_t
    counts[4][MAX_BASES+1] = {0};

int main() {
    int32_t
        ch;
    uint32_t
        nBases=0,
        nQueries,
        qCount[4],
        first,last;

    while (true) {
        ch = cin.get();
        if (ch == '\n')
            break;

        nBases++;

        REPI(i,0,4)
            counts[i][nBases] = counts[i][nBases-1] + ((ch == BASES[i]) ? 1 : 0);
    }

    cin >> nQueries;

    REPI(i,0,nQueries) {
        cin >> first >> last;

        REPI(j,0,4)
            qCount[j] = (counts[j][last] - counts[j][first - 1]) * 10 + 3 - j;

        REPI(j,0,3)
            REPI(k,0,3)
                if (qCount[k] < qCount[k+1])
                    swap(qCount[k],qCount[k+1]);

        REPI(j,0,4)
            cout << BASES[3-qCount[j] % 10];
        cout << endl;
    }

    return 0;
}
