#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, w;
    scanf("%d%d",&n,&w);
    vector<int> p(n);

    for (int i = 0; i < n; ++i) {
        cin >> p[i];
    }
    
    sort(p.begin(), p.end());

    bool ban = true;
    for (int i = 0; i < n - w; ++i) {
        if (p[i] >= p[i + w]) {
            ban = false;
            break;
        }
    }

    if (ban) {
        cout << "yes\n";
    } else {
        cout << "no\n";
    }

    return 0;
}