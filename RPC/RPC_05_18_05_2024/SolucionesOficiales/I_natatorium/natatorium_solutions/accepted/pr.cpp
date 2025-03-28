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
ll mm(ll a,ll b,ll M){
    ll y=a*(long double)b/M+.5,r=a*b-y*M;
    return r<0?r+M:r;
}
ll pw(ll n,ll k,ll M){
    ll r=1;
    while(k){
        if(k&1)r=mm(r,n,M);
        n=mm(n,n,M),k>>=1;
    }
    return r%M;
}
bool PT(ll n,int W){
    ll N=n-1,S;
    int s=0;
    while(!(N&1))N>>=1,s++;
    S=pw(W,N,n);
    if(S==1||S==n-1)return 1;
    while(--s>=0)if((S=mm(S,S,n))==n-1)return 1;
    return 0;
}
bool isP(ll n){
    if(n<4)return n>1;
    if(n<1373653)return PT(n,2)&&PT(n,3);
    if(n<25326001)return PT(n,5);
    if(n==3215031751)return 0;
    if(n<25000000000ll)PT(n,7);
    if(n<2152302898747ll)return PT(n,11);
    if(n<3474749660383ll)PT(n,13);
    if(n<341550071728321ll)  return PT(n,17);
    int r[]={19,23,29,31,37};
    F(5)if(!PT(n,r[i]))return 0;
    return 1; 
}
ll rnd(int b){ll r(0);F(b)r<<=1,r|=rand()&1;return r;}
#define GF(X) (mm(X,X,N)+c)%N
ll rho(ll N){
    if(!(N&1))return 2;
    ll d,c(rnd(ceil(log2(N)-ZERO))),x(rnd(ceil(log2(N)-ZERO))),xx=x;
    do x=GF(x),xx=GF(xx),xx=GF(xx),d=__gcd(llabs(x-xx),N); while(d==1);
    return d;
}
int ff(ll N,ll*f,int L){
    if(N<=1)return L;
    if(isP(N))return f[L]=N,++L;
    ll d(N);
    while(d==N)d=rho(N);
    return ff(N/d,f,ff(d,f,L));
}
int fc(ll N,ll*f,int*c){
    static ll G[66];
    int L(ff(N,G,0)),I(0),l(0);
    G[L]=-1;
    sort(G,G+L);
    while(I<L){
        f[l]=G[I++],c[l]=1;
        while(G[I]==G[I-1])++c[l],++I;
        ++l;
    }
    return l;
}
ll a[100];
int b[100];
int main(void){
    ll T;
    scanf("%lld",&T);
    fc(T, a, b);
    printf("%lld %lld\n", *a, a[1]);
    return 0;
}
