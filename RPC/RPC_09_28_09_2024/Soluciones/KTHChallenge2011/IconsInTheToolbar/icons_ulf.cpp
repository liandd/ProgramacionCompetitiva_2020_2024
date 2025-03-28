/* Solution to "Icons in the Toolbar" from KTH Challenge 2011
** Author: Ulf Lundström
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define rep(i,a,b) for(__typeof(b) i=a; i<(b); ++i)

typedef long long ll;
typedef vector<ll> vll;

int main()
{
    ll N;
    cin >> N;
    vll a(2*N,0), sum(2*N+1,0), sum2(2*N+2,0);
    rep(i,0,2*N) {
        cin >> a[i];
        sum[i+1] = sum[i]+a[i];
        if (i%2==0)
            sum2[i+2] = sum2[i]+a[i];
    }
    ll best = 1ll<<62;
    rep(i,0,N+1) {
        ll w = sum[i]+sum2[2*N]-sum2[2*i];
        ll h = a[0] + a[i];
        best = min(best,w*h);
    }
    cout << best << endl;
}
