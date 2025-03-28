#include<iostream>
using namespace std;

struct Card
{
    char rank, suit;
};

Card hand[52];

void printHand(int num)
{
    cout << num;
    for(int i=0; i<num; i++) {
        cout << " " << hand[i].rank << hand[i].suit;
    }
    cout << endl;
}

int main() {

    int j = 0, i=0;
    bool dealCard = true;
    while (i < 52 || !dealCard) {
        if (dealCard) {
            string s;
            cin >> s;
            hand[j].rank = s[0];
            hand[j].suit = s[1];
            i++;
        }
        dealCard = false;
        int k=j-3;
        while (k >=0 && hand[k].rank != hand[k+3].rank)
            k--;
        if (k >= 0) {
            for(; k<=j-4; k++)
                hand[k] = hand[k+4];
            j -= 4;
            continue;
        }
        k=j-3;
        while (k >=0 && hand[k].suit != hand[k+3].suit)
            k--;
        if (k >= 0) {
            hand[k] = hand[k+1];
            k++;
            hand[k] = hand[k+1];
            k++;
            for(; k<=j-2; k++)
                hand[k] = hand[k+2];
            j -= 2;
            continue;
        }
        dealCard = true;
        j++;
    }
    printHand(j);
}
