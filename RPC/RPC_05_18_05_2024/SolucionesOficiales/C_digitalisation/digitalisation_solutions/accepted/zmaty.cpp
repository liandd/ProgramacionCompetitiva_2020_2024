#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using ld=double;
using vll=vector<ll>;
using vvll=vector<vector<ll>>;
#define FOR(i,a,b) for(ll i=a;i<(ll)b;++i)
#define F(n) FOR(i,0,n)
#define FF(n) FOR(j,0,n)
#define aa first
#define bb second
#define PB push_back
#define EQ(a,b) (fabs(a-b)<=(fabs(a+b)*EPS))
#define MOD ((ll)(1e9+7))
#define dbg cerr
#define out(n) cout << n << '\n'

//#define dbg if(0)cerr

int main(){
  ios::sync_with_stdio(0);cin.tie(0);
  ll n, m, c;
  cin>>n>>m>>c;
  vector<ll> left(m, c);
  ll onlyb=0,onlyr=0;
  F(n) {
    ll b, r;
    cin>>b>>r;
    assert(b != r);
    b--; r--;
    if (left[b]) onlyr++, left[b]--;
    else if (left[r]) onlyb++, left[r]--;
  }
  cout << onlyr << ' ' << onlyb << endl;
  return 0;
}

/*
assert will terminate the program (usually with a message quoting the assert statement) if its argument turns out to be false. It's commonly used during debugging to make the program fail more obviously if an unexpected condition occurs.

For example:

assert(length >= 0);  // die if length is negative.

You can also add a more informative message to be displayed if it fails like so:

assert(length >= 0 && "Whoops, length can't possibly be negative! (didn't we just check 10 lines ago?) Tell jsmith");

Or else like this:

assert(("Length can't possibly be negative! Tell jsmith", length >= 0));
*/