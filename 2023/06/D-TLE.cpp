#include<bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, q;
    cin >> n >> q;

    vector<int> collection(n);
    for (int i = 0; i < n; i++) {
        cin >> collection[i];
    }

    sort(collection.begin(), collection.end());

    while (q--) {
        int op, a, b;
        cin >> op >> a >> b;

        if (op == 1) {
            auto it = upper_bound(collection.begin(), collection.end(), a);
            if (it != collection.end() && *it == a) {
                continue;
            }
            collection.insert(it, a);
        }
        else {
            auto lower = lower_bound(collection.begin(), collection.end(), a);
            auto upper = upper_bound(collection.begin(), collection.end(), b);
            cout << upper - lower << "\n";
        }
    }

    cout << flush;

    return 0;
}
