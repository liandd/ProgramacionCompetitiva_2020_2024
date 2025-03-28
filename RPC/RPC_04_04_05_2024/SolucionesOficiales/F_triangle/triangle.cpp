// Arup Guha
// 8/17/2023
// Alternate Solution to 2023 UCF Locals Qualifying Problem: Close Triangles

using namespace std;
#include <bits/stdc++.h>

int n;
vector<int> x;
vector<int> y;
vector<int> aMap;

int go(vector<int>& perm, vector<bool>& used, int k);
int eval(vector<int>& perm);
int get2A(int a, int b, int c);

int main() {

    // Area map.
    for (int i=0; i<15*15*15; i++) aMap.push_back(0);

    cin >> n;

    // Read in pts.
    for (int i=0; i<3*n; i++) {
        int myx, myy;
        cin >> myx >> myy;
        x.push_back(myx);
        y.push_back(myy);
    }

    // Area pre-comp.
    for (int i=0; i<3*n; i++)
        for (int j=i+1; j<3*n; j++)
            for (int k=j+1; k<3*n; k++)
                aMap[225*i+15*j+k] = get2A(i,j,k);

    // Run it!
    vector<int> perm(3*n);
    vector<bool> used(3*n, false);
    printf("%.1f\n", go(perm, used, 0)/2.0);

    return 0;
}

// Solves the problem with the first k triangles fixed in perm.
int go(vector<int>& perm, vector<bool>& used, int k) {

    // Base case.
    if (k == n) return eval(perm);

    // Find first unused.
    int s = -1;
    for (int i=0; i<used.size(); i++) {
        if (!used[i]) {
            s = i;
            break;
        }
    }

    // Way too big =)
    int res = 1000000000;

    // Brute force last two triangle vertices.
    for (int i=s+1; i<3*n; i++) {
        if (used[i]) continue;
        for (int j=i+1; j<3*n; j++) {
            if (used[j]) continue;

            // Put these into the next three slots and recurse.
            used[s] = true; used[i] = true; used[j] = true;
            perm[3*k] = s; perm[3*k+1] = i; perm[3*k+2] = j;
            int tmp = go(perm, used, k+1);

            // Update our answer.
            res = min(res, tmp);

            // Undo.
            used[s] = false; used[i] = false; used[j] = false;
        }
    }

    // Ta da!
    return res;
}

// Evaluates the difference in areas between smallest or largest triangles as specified by perm.
// Returns twice this area.
int eval(vector<int>& perm) {
    int lo = aMap[225*perm[0]+15*perm[1]+perm[2]];
    int hi = lo;
    for (int i=1; i<n; i++) {
        int tmp = aMap[225*perm[3*i]+15*perm[3*i+1]+perm[3*i+2]];
        lo = min(lo, tmp);
        hi = max(hi, tmp);
    }
    return hi - lo;
}

// Returns twice area of triangle with indexes a, b and c.
int get2A(int a, int b, int c) {
    int v1x = x[b] - x[a];
    int v1y = y[b] - y[a];
    int v2x = x[c] - x[a];
    int v2y = y[c] - y[a];
    return abs(v1x*v2y-v1y*v2x);
}
