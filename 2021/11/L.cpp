#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, vista = 0;
    cin>>n;
    while(n--) {
        int l, c1, c2;
        cin>>l>>c1>>c2;
        int next1, next2;
        next1 = l + c1;
        next2 = l + c2;
        while (next1 != next2) {
            if (next1 < next2) {
                next1 += c1;
            } else {
                next2 += c2;
            }
        }
        int res = next1;
        if (vista == 0 || res < vista)
            vista = res;
    }
    cout<<vista<<endl;
    return 0;
}
