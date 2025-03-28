#include <iostream>

using namespace std;

#define REPI(ctr,start,limit) for (uint32_t ctr=(start);(ctr)<(limit);(ctr)++)

const uint32_t
    MAX_BASES = 50000;

const char
    BASES[] = "ATGC";

char
    input[MAX_BASES+1];

int main() {
    int32_t
        ch;
    uint32_t
        nBases=0,
        nQueries,
        qCount[4],
        first,last;

    cin >> input >> nQueries;

    REPI(i,0,nQueries) {
        cin >> first >> last;

        REPI(j,0,4)
            qCount[j] = 0;

        REPI(j,first-1,last)
            REPI(k,0,4)
                if (input[j] == BASES[k])
                    qCount[k]++;

        REPI(j,0,4)
            qCount[j] = qCount[j] * 10 + 3 - j;

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
