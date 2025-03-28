#include <iostream>

using namespace std;

#define REPI(ctr,start,limit) for (uint32_t ctr=(start);(ctr)<(limit);(ctr)++)

const string
    RANKS = "A23456789TJQK";

uint64_t try15(uint32_t cc,uint32_t s,uint32_t cards[],uint32_t n) {
    uint64_t
        temp = 0;

    if (s == 0)
        return 2;
    if (cc == n)
        return 0;
    if (cards[cc] <= s)
        temp = try15(cc+1,s-cards[cc],cards,n);
    return temp + try15(cc+1,s,cards,n);
}

int main() {
    uint64_t
        nCards,
        score=0,
        nPerRank[13]={0},
        tmp, j, runLen;
    uint32_t
        cards[100];
    char
        ch;

    cin >> nCards;

    REPI(i,0,nCards) {
        cin >> ch;
        nPerRank[RANKS.find(ch)]++;
        cards[i] = RANKS.find(ch);
    }

    // pairs
    REPI(i,0,13)
        score += nPerRank[i] * (nPerRank[i] - 1);

    // runs
    for (uint32_t i=0;i<=10;) {
        if (nPerRank[i] > 0 && nPerRank[i+1] > 0 && nPerRank[i+2] > 0) {
            tmp = 1;
            j = i;
            runLen = 0;
            while (j < 13 && nPerRank[j] > 0) {
                tmp *= nPerRank[j];
                j++;
                runLen++;
            }
            score += tmp * runLen;
            i += runLen;
        } else
            i++;
    }

    // 15s
    REPI(i,0,nCards)
        if (cards[i] > 9)
            cards[i] = 10;
        else
            cards[i]++;
    score += try15(0,15,cards,nCards);

    cout << score << endl;

    return 0;
}
