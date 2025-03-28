#include<bits/stdc++.h>

using namespace std;

const long long MOD = 1000000007;


vector<vector<vector<vector<long long>>>> dp;

int main() {
    int a, b, c;
    cin >> a >> b >> c;


    dp.resize(3, vector<vector<vector<long long>>>(a + 1, vector<vector<long long>>(b + 1, vector<long long>(c + 1, 0))));
    dp[0][1][0][0] = 1;
    dp[1][0][1][0] = 1;
    dp[2][0][0][1] = 1;

    for (int i = 0; i <= a; i++) {
        for (int j = 0; j <= b; j++) {
            for (int k = 0; k <= c; k++) {

                for (int z = 0; z < 3; z++) {

                    if (z == 0 && i == 0) continue;
                    if (z == 1 && j == 0) continue;
                    if (z == 2 && k == 0) continue;


                    if (z == 0 && i > 0) dp[z][i][j][k] = (dp[z][i][j][k] + dp[1][i-1][j][k] + dp[2][i-1][j][k]) % MOD;
                    if (z == 1 && j > 0) dp[z][i][j][k] = (dp[z][i][j][k] + dp[0][i][j-1][k] + dp[2][i][j-1][k]) % MOD;
                    if (z == 2 && k > 0) dp[z][i][j][k] = (dp[z][i][j][k] + dp[0][i][j][k-1] + dp[1][i][j][k-1]) % MOD;
                }
            }
        }
    }


    long long res = 0;
    for (int i = 0; i < 3; i++) {
        res = (res + dp[i][a][b][c]) % MOD;
    }


    cout << res << endl;

    return 0;
}




/*#include<bits/stdc++.h>

using namespace std;

const int MOD = 1e9 + 7;

int contar_arreglos_validos(int a, int b, int c) {
    vector<vector<vector<vector<int>>>> dp(a + 1, vector<vector<vector<int>>>(b + 1, vector<vector<int>>(c + 1, vector<int>(3, 0))));

    if (a > 0) dp[1][0][0][0] = 1;
    if (b > 0) dp[0][1][0][1] = 1;
    if (c > 0) dp[0][0][1][2] = 1;

    // Llenar la tabla dp
    for (int i = 0; i <= a; ++i) {
        for (int j = 0; j <= b; ++j) {
            for (int k = 0; k <= c; ++k) {
                for (int ultimo = 0; ultimo < 3; ++ultimo) {
                   // if (i + j + k == 1) continue;
                    if (ultimo == 0 && i > 0) {
                        dp[i][j][k][0] = (dp[i-1][j][k][1] + dp[i-1][j][k][2]) % MOD;
                    } else if (ultimo == 1 && j > 0) {
                        dp[i][j][k][1] = (dp[i][j-1][k][0] + dp[i][j-1][k][2]) % MOD;
                    } else if (ultimo == 2 && k > 0) {
                        dp[i][j][k][2] = (dp[i][j][k-1][0] + dp[i][j][k-1][1]) % MOD;
                    }
                }
            }
        }
    }

    int total_arreglos = (dp[a][b][c][0] + dp[a][b][c][1] + dp[a][b][c][2]) % MOD;
    return total_arreglos;
}

int main() {
    int a, b, c;
    cin >> a >> b >> c;
    cout << contar_arreglos_validos(a, b, c) << endl;
    return 0;
}*/
