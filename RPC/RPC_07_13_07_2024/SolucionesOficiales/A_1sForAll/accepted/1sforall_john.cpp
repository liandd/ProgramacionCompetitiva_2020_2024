#include <iostream>
#include <sstream>
#include <cstdio>
#include <cmath>
using namespace std;

const int MAXN = 150000;
int table[MAXN+1];

int main() {

    stringstream ss;
    int n;

    cin >> n;
    table[0] = MAXN;
    table[1] = 1;
    for(int i=2; i<=n; i++) {
        table[i] = MAXN;
                                    // check for a+b=i
        for(int j=1; j<= i/2; j++) {
            if (table[j] + table[i-j] < table[i]) {
                table[i] = table[j] + table[i-j];
            }
        }
                                    // check for a*b = i
        for(int j=2; j<sqrt(i+1); j++) {
            if (i%j == 0 && table[j] + table[i/j] < table[i]) {
                table[i] = table[j] + table[i/j];
            }
        }
/**/
                                    // check for a@b = i
        string s = to_string(i);
        for(int j=1; j<s.length(); j++) {
            int n1, n2;
            ss.clear();
            ss << s.substr(0,j) << ' ' << s.substr(j);
            ss >> n1 >> n2;
            if (table[n1] + table[n2] < table[i] && s[j] != '0') {
                table[i] = table[n1] + table[n2];
            }
        }
/**/
    }

    cout << table[n] << endl;
}

