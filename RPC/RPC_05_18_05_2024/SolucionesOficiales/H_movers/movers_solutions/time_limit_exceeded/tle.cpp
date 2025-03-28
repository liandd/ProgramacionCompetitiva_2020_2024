#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main(){
    ll N, M, Q;
    cin >> N >> M >> Q;
    vector<ll> desks(N); for(ll &a:desks) cin>>a;
    vector<ll> monitors(N); for(ll &a:monitors) cin>>a;
    vector<vector<ll>> G(N);
    for(ll i=0; i<M; ++i){
        ll a, b; cin >> a >> b; --a; --b;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    for(ll i=0; i<Q; ++i){
        string cmd;
        cin >> cmd;
        if(cmd == "add"){
            string who;
            ll count, to;
            cin >> count >> who >> to; --to;
            if(who == "desk"){
                desks[to] += count;
            }else if(who == "monitor"){
                monitors[to] += count;
            } else assert(false);
        } else if(cmd == "check"){
            int vertex;
            cin >> vertex; --vertex;
            ll sumd = desks[vertex], sumg = monitors[vertex];
            for(ll n:G[vertex]){
                sumd += desks[n];
                sumg += monitors[n];
            }
            if(sumd == sumg){
                cout << "same" << endl;
            }else if(sumd > sumg){
                cout << "desks" << endl;
            }else{
                cout << "monitors" << endl;
            }
        } else assert(false);
    }
    return 0;
}
