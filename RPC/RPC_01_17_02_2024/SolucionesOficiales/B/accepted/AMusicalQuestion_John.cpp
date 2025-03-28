#include<iostream>
using namespace std;

int main() {

    int size, n;

    cin >> size >> n;
    int times[n+1];
    for(int i=1; i<=n; i++)
        cin >> times[i];

    char table[2][size+1][size+1];
    for(int i=0; i<=0; i++) {
        for(int j=0; j<=size; j++) {
            for(int k=0; k<=size; k++) {
                table[i][j][k] = false;
            }
        }
    }
    table[0][size][size] = true;
    for(int i=1; i<=n; i++) {
        for(int j=0; j<=size; j++) {
            for(int k=0; k<=size; k++) {
                table[1][j][k] = table[0][j][k];
                if (j + times[i] > 0 && j + times[i] <= size && table[0][j+times[i]][k]) // j+times[i]>0 checks for overflow
                    table[1][j][k] = true;
                if (k + times[i] > 0 && k + times[i] <= size && table[0][j][k+times[i]])
                    table[1][j][k] = true;;
            }
        }
        for(int j=0; j<=size; j++) {
            for(int k=0; k<=size; k++) {
                table[0][j][k] = table[1][j][k];
            }
        }
//			cout << "i = " << i << endl;
//			for(int j=0; j<=size; j++) {
//				for(int k=0; k<=size; k++) {
//					int val = table[1][j][k] ? 1 : 0;
//					cout << val << " ";
//				}
//				cout << endl;
//			}
    }
//    cout << "here" << endl;
                                    // search diagonals of last slice of table for minimal empty space
    bool found = false;
    int cd1 = 0, cd2 = 0;
    for(int empty=0; empty<=2*size; empty++) {		// empty = remaining minutes not used on two CDs combined
        for(int i=max(0, empty-size); i<=size; i++) {
            int j=empty-i;
            if (j < i)
                break;
            if (table[0][i][j]) {
                found = true;
                cd1 = size-i;
                cd2 = size-j;
            }
        }
        if (found)
            break;
    }
    cout << cd1 << " " << cd2 << endl;

}
