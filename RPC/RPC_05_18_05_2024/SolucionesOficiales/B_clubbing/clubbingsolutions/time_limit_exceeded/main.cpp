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
int N;
ll T;
set<int> S;
string s;
int sts(string s){
    int H = 0;
    F(s.size())
        H |= 1<<(s[i]-97);
    return H;
}
int main(void){
    cin >> N;
    F(N)cin >> s,S.insert(sts(s));
    cin >> s;
    F(s.size()){
        int H = 0;
        FT(i, s.size())
            if (!(H&(1<<(s[k]-97)))){
                H |= 1<<(s[k]-97);
                for(auto&h:S)
                    if ( (h&H) == h){
                        T += s.size() - k;
                        k = 1e9;
                        break;
                    }
            }
    }
    cout << T << endl;
    return 0;
}
