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
#define UU 17
#define MX (1<<UU)
int toby(string s){
    int H=0;
    for(auto&h:s)
        H|=1<<(h-'a');
    return H;
}
bitset<MX> G;
int N,I ,J, X, C[UU], H;
ll T;
string s;
int main(void){
    cin >> N;
    F(N) cin >> s, G[toby(s)]=1;
    F(MX)FF(UU)if((i&(1<<j))&& G[i^(1<<j)])G[i]=1;
    cin >> s;
    while(I<int(s.size())){
        while(J<int(s.size()) && !G[H]){
            if(!C[s[J]-97]++)H^=1<<(s[J]-97);
            ++J;
        }
        if(G[H]) T+=s.size()-J+1;
        if(!--C[s[I]-97])H^=1<<(s[I]-97);
        ++I;
    }
    cout << T << endl;
    return 0;
}
