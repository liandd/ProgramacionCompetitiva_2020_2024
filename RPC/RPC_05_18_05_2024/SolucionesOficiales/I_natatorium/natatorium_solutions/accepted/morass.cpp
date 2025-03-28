#include <bits/stdc++.h>
using namespace std;
#define PB push_back
#define ZERO (1e-10)
#define INF int(1e9+1)
#define CL(A,I) (memset(A,I,sizeof(A)))
#define DEB printf("DEB!\n");
#define D(X) cout<<"  "<<#X": "<<X<<endl;
#define EQ(A,B) (A+ZERO>B&&A-ZERO<B)
typedef long long ll;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;
#define IN(n) int n;scanf("%d",&n);
#define FOR(i, m, n) for (int i(m); i < n; i++)
#define F(n) FOR(i,0,n)
#define FF(n) FOR(j,0,n)
#define FT(m, n) FOR(k, m, n)
#define aa first
#define bb second
void ga(int N,int *A){F(N)scanf("%d",A+i);}
vector<ll> v;
int main(void){
    ll T, N;
    scanf("%lld %lld", &T, &N);
    F(N){
        ll a;
        scanf("%lld", &a);
        if(!(T%a)) v.PB(a);
    }
    assert(v[0]!=v[1]);  // TODO ERASE!
    printf("%lld %lld\n", min(v[0], v[1]), max(v[0], v[1]));
    return 0;
}
