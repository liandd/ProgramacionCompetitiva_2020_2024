#include<bits/stdc++.h>
using namespace std;
#define fo(i,n) for(auto i=0;i<n;i++)
#define ll long long
#define si(x)	scanf("%d",&x)
#define sl(x)	scanf("%lld",&x)
#define ss(s)	scanf("%s",s)
#define pi(x)	printf("%d\n",x)
#define pl(x)	printf("%lld\n",x)
#define ps(s)	printf("%s\n",s)
#define pb push_back
#define F first
#define S second
typedef vector<ll>		vl;
typedef pair<ll, ll>	pl;
vl p;

const int N = 1e5;

bool a[N];
int prime[N];

int sieve() {
    int ind = 0, sq = sqrt(N) + 1;
    for (int i = 2; i < sq; i++) {
        if (a[i] == 0) {
            for (int j = 2*i; j < N; j += i) a[j] = 1;
        }
    }
    for (int i = 2; i < N; i++) if (a[i] == 0) prime[ind++] = i;
    return ind; 
}

int numberOfDivisor(int n) {
    int sum = 1, sq = sqrt(n) + 1;
    for (int i = 0; prime[i] < sq; i++) {
        if (n % prime[i] == 0) {
            int c = 0;
            while (n % prime[i] == 0) {
                n /= prime[i];
                c++;
            }
            sum *= (c+1);
        }
    }
    if (n > 1) sum *= 2;
    return sum;
}

int main() {
    // freopen("in", "r", stdin);

    sieve();
    
    int n;
    cin>>n;
    for(int i = 0; i<n; i++){
        int aux;
        cin>>aux;
        int j = 1;
        bool b = 1;
        while(j < 10e23 && b){
            if(numberOfDivisor(j) == aux){
                cout<<j<<"\n";
                b = 0;
            }
            j++;
        }
    }
    return 0;
}