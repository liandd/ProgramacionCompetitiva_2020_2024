#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int q;
    cin >> q;
    map<int, int> mapa;
    mapa[1] = 1;
    for (long long i = 1; i <= 1e5; i++){
        long long prod = 1;
        for (long long j=0; j<=(i + 1) / 2; j++){
            prod *= i - j;
            prod /= j + 1;
            if (prod > 1e9) break;
            if (mapa.find(prod) == mapa.end()) mapa[prod] = i + 1;
        }
    }
    while (q--){
        int n;
        cin >> n;
        if (mapa.find(n) == mapa.end()) cout << n + 1 << '\n';
        else cout << mapa[n] << '\n';
    }
    return 0;
}
