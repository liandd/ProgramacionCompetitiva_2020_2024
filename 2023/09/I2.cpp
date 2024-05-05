#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, q;
    cin >> n >> q;

    unordered_map<string, int> intersectionToIndex;
    vector<string> streets(n);
    for (int i = 0; i < n; ++i) {
        cin >> streets[i];
        intersectionToIndex[streets[i]] = i;
    }

    for (int i = 0; i < q; ++i) {
        string start, end;
        cin >> start >> end;

        int startIndex = intersectionToIndex[start];
        int endIndex = intersectionToIndex[end];

        if (startIndex > endIndex) {
            swap(startIndex, endIndex);
        }

        int diff = endIndex - startIndex;
        if (diff == 1) {
            cout << "0\n";
        } else {
            cout << (diff - 1) << "\n";
        }
    }

    return 0;
}
