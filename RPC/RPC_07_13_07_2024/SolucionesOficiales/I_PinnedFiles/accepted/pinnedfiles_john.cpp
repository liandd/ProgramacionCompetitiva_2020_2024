#include <iostream>
using namespace std;

const int MAXVALS = 100;

int mapping[MAXVALS+1];
int finalOrder[MAXVALS];

int main()
{
    int p1, u1, p2, u2;
    int val;

    cin >> p1 >> u1;
    for(int i=1; i<=p1+u1; i++) {
        cin >> val;
        mapping[val] = i;			// renumber initial list of files to 1,2,..., (p1+u1)
    }
    cin >> p2 >> u2;
    for(int i=0; i<p2+u2; i++) {
        cin >> val;
        finalOrder[i] = mapping[val];
    }
                                // handled moves for final pinned files
    int numMoves = 0;
    bool noMove = true;
    for(int i=0; i<p2; i++) {
        if (noMove) {
            if (finalOrder[i] > p1) {	//unpinned becomes pinned
                noMove = false;
                numMoves++;
            }
            else if (i>0 && finalOrder[i] < finalOrder[i-1]) {	// pinned in new order
                noMove = false;
                numMoves += 2;
            }
        }
        else if (finalOrder[i] > p1)
            numMoves++;
        else
            numMoves += 2;
    }
                                // handled moves for final unpinned files
    noMove = true;
    for(int i=p2+u2-1; i>=p2; i--) {
        if (noMove) {
            if (finalOrder[i] <= p1) {	// pinned becomes unpinned
                noMove = false;
                numMoves++;
            }
            else if (i<p2+u2-1 && finalOrder[i] > finalOrder[i+1]) {	// unpinned in new order
                noMove = false;
                numMoves += 2;
            }
        }
        else if (finalOrder[i] <= p1)
            numMoves++;
        else
            numMoves += 2;
    }
    cout << numMoves << endl;
}
