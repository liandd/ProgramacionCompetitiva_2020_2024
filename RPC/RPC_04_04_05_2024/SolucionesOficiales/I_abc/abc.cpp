
// Problem: Know Your ABC's
// Solution Author: Coach Travis

// This solution uses dynamic programming

// Include the useful parts of c++
#include <bits/stdc++.h>

// Ensure that std is not everywhere
using namespace std;

// The mod value
#define MOD 1000000007

// The memo table
int **** memo;

// dp function
int go(int a, int b, int c, int last) {
    // BASE CASE
    if (!a && !b && !c) {
        return 1;
    }
    
    // MEMO CHECK
    if (memo[a][b][c][last] != -1) {
        return memo[a][b][c][last];
    }

    // Start answer as zero
    memo[a][b][c][last] = 0;
    
    // Try ending with A
    if (a && last != 0)
        memo[a][b][c][last] = go(a-1,b,c,0);
        
    // Try ending with B
    if (b && last != 1)
        memo[a][b][c][last] += go(a,b-1,c,1);

    // Avoid overflow
    memo[a][b][c][last] %= MOD;

    // Try ending with C
    if (c && last != 2)
        memo[a][b][c][last] += go(a,b,c-1,2);
    
    // mod by the required modulo
    memo[a][b][c][last] %= MOD;
    
    // Return the answer
    return memo[a][b][c][last];
}

// The main function
int main() {
    // Read in the number of each block
    int a, b, c;
    cin >> a >> b >> c;
    
    // Make the memo table and fill with sentinel value of -1
    memo = new int***[a+1];
    for (int i = 0; i <= a; i++) {
        memo[i] = new int**[b+1];
        for (int j = 0; j <= b; j++) {
            memo[i][j] = new int*[c+1];
            for (int k = 0; k <= c; k++) {
                memo[i][j][k] = new int[4];
                for (int m = 0; m <= 4; m++) {
                    memo[i][j][k][m] = -1;
                }
            }
        }
    }

    // Print the answer
    cout << go(a,b,c,3) << endl;
	
    // Clean up memory
    for (int i = 0; i <= a; i++) {
        for (int j = 0; j <= b; j++) {
            for (int k = 0; k <= c; k++) {
                delete[] memo[i][j][k];
            }
            delete[] memo[i][j];
        }
        delete[] memo[i];
    }
    delete[] memo;

    // Exit the program
    return 0;
}
