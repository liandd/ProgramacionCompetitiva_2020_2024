// Arup Guha
// 8/11/2023
// Solution to 2023 UCF Local Qualifying Round Problem: Weighted Window Sum

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

    // Calculate current sum.
    ll curS = 0, regS = 0;
    for (int i=0; i<k; i++) {
        curS += (i+1)*nums[i];
        regS += nums[i];
    }

    // Set up first window.
    windows[0].first = curS;
    windows[0].second = 1;

    // Now go right, and quickly calculate each subsequent window.
    for (int i=k; i<n; i++) {

        // Each term in the old sum "goes down by 1 copy" in the new one.
        curS -= regS;

        // This is the standard update to the new regular window sum.
        regS = regS - nums[i-k] + nums[i];

        // Now, the new term is weighted by k.
        curS += (k*nums[i]);

        // Now, we are ready to copy in this information.
        windows[i-k+1].first = curS;
        windows[i-k+1].second = i-k+2;
    }

    // Sort it!
    sort(windows.begin(), windows.end());

    // Ta da!
    for (int i=0; i<windows.size(); i++)
        cout << windows[i].second << " " << windows[i].first << endl;

    return 0;
}
