// Arup Guha
// 8/13/2024
// Solution to 2024 UCF Locals Problem: Ready for Contest

using namespace std;
#include <bits/stdc++.h>

int main() {

    int n, sols;
    cin >> n >> sols;

    // Initialize solution list.
    vector<bool> cpp(n, false);
    vector<bool> java(n, false);

    // Process solutions.
    for (int i=0; i<sols; i++) {
        int prob, lang;
        cin >> prob >> lang;
        prob--;

        // Mark the appropriate one.
        if (lang == 1) cpp[prob] = true;
        if (lang == 2) java[prob] = true;

    }

    // Output everything we have the appropriate two solutions for.
    for (int i=0; i<n; i++)
        if (cpp[i] && java[i])
            cout << i+1 << endl;

    return 0;
}
