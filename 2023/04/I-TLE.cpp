#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    
    vector<int> b(k);
    for (int i = 0; i < k; i++) {
        cin >> b[i];
    }
    
    int grosor = 0;
    vector<int> g(n);
    for (int i = 0; i < n; i++) {
        int f = (a[i] < 0) ? -a[i] : 0;
        int t = (a[i] > 0) ? a[i] : 0;
        grosor += f / 5 - t / 5;
        if (grosor < 0) {
            grosor = 0;
        }
        g[i] = grosor;
    }
    
    vector<int> c(k);
    for (int i = 0; i < k; i++) {
        int g_min = b[i];
        for (int j = 0; j < n; j++) {
            if (g[j] >= g_min) {
                c[i]++;
            }
        }
    }
    
    for (int i = 0; i < k; i++) {
        cout << c[i] << " ";
    }
    cout << "\n";
    
    return 0;
}
