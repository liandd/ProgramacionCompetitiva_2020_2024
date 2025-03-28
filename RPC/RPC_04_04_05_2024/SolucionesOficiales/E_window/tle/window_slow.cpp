// Arup Guha
// 8/15/2023
// Weighted Window Sum TLE Submission

using namespace std;
#include <bits/stdc++.h>
typedef long long ll;

int main() {

    // Read in numbers.
    int n, k;
    cin >> n >> k;
    vector<ll> nums(n);
    for (int i=0; i<n; i++)
        cin >> nums[i];

    vector< pair<ll,int> > windows(n-k+1);

    // Here is our n-sqr behavior
    for (int i=0; i<n-k+1; i++) {
        ll curS = 0;
        for (int j=i,z=1; j<i+k; j++,z++)
            curS += (z*nums[j]);
        windows[i].first = curS;
        windows[i].second = i+1;
    }

    // Sort it!
    sort(windows.begin(), windows.end());

    // Ta da!
    for (int i=0; i<windows.size(); i++)
        cout << windows[i].second << " " << windows[i].first << endl;

    return 0;
}
