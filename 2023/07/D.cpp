#include <bits/stdc++.h>
using namespace std;

bool isValid(string& binaryString, int k) {
    int consecutiveZeros = 0;
    int consecutiveOnes = 0;

    for (char bit : binaryString) {
        if (bit == '0') {
            consecutiveZeros++;
            consecutiveOnes = 0;
        } else {
            consecutiveZeros = 0;
            consecutiveOnes++;
        }

        if (consecutiveZeros > k || consecutiveOnes > k) {
            return false;
        }
    }

    return true;
}

int countValid(int n, int k) {
    int cont = 0;
    int combinations = pow(2, n);

    for (int i = 0; i < combinations; i++) {
        string binaryString = bitset<20>(i).to_string().substr(20 - n);
        if (isValid(binaryString, k)) {
            cont++;
        }
    }

    return cont;
}

int main() {
    int n, k;
    cin >> n >> k;

    int r = countValid(n, k);
    cout << r << "\n";

    return 0;
}
