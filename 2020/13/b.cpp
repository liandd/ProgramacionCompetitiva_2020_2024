#include <bits/stdc++.h>

using namespace std;

int main() {
    long long int x;
    cin>>x;
    while(x--) {
        long long int a, b, res, total;
        cin>>a>>b;
        res = a % b;
        total = (res == 0) ? 0 : b - res;
        cout<<total<<endl;
    }
    return 0;
}
