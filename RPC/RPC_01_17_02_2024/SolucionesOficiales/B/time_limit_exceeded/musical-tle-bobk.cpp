#include <iostream>

using namespace std;

uint32_t
    cd1=0,cd2=0,
    c,n,
    times[1000];

void solve(uint32_t m1,uint32_t m2,uint32_t level) {

    if (level == n) {
        if (m1 + m2 > cd1 + cd2) {
            cd1 = max(m1,m2);
            cd2 = min(m1,m2);
        } else if (m1 + m2 == cd1 + cd2) {
            int32_t d = m1 - m2;
            if (d < 0)
                d = -d;
            if (d < cd1 - cd2) {
                cd1 = max(m1,m2);
                cd2 = min(m1,m2);
            }
        }

        return;
    }

    solve(m1,m2,level+1);

    if (m1 + times[level] <= c)
        solve(m1+times[level],m2,level+1);

    if (m2 + times[level] <= c)
        solve(m1,m2+times[level],level+1);
}

int main() {

    cin >> c >> n;
    for (int i=0;i<n;i++)
        cin >> times[i];

    solve(0,0,0);

    cout << cd1 << ' ' << cd2 << endl;

    return 0;
}
