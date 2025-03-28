#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main(){
    ll N, M, Q;
    cin >> N >> M >> Q;
    vector<ll> desks(N); for(ll &a:desks) cin>>a;
    vector<ll> monitors(N); for(ll &a:monitors) cin>>a;
    vector<vector<ll>> G(N), sparse(N);
    for(ll i=0; i<M; ++i){
        ll a, b; cin >> a >> b; --a; --b;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    vector<bool> high_degree(N);
    for(ll i=0; i<N; ++i){
        high_degree[i] = G[i].size() > sqrt(N);
    }
    vector<ll> res_desks(N);
    vector<ll> res_monitors(N);
    for(ll i=0; i<N; ++i){
        if(high_degree[i]){
            res_desks[i] = desks[i];
            res_monitors[i] = monitors[i];
            for(ll j : G[i]){
                res_desks[i] += desks[j];
                res_monitors[i] += monitors[j];
            }
        }
        for(ll j : G[i]){
            if(high_degree[j]){
                sparse[i].push_back(j);
            }
        }
    }
    for(ll i=0; i<Q; ++i){
        string cmd;
        cin >> cmd;
        if(cmd[0] == 'a'){ // add
            string who;
            ll count, to;
            cin >> count >> who >> to; --to;
            if(who[0] == 'd'){ // desk
                desks[to] += count;
                res_desks[to] += count;
                for(ll n:sparse[to])res_desks[n] += count;
            }else{ // monitor
                monitors[to] += count;
                res_monitors[to] += count;
                for(ll n:sparse[to])res_monitors[n] += count;
            }
        } else {
            ll vertex;
            cin >> vertex; --vertex;
            ll sumd = 0;
            ll sumg = 0;
            if(high_degree[vertex]){
                sumd = res_desks[vertex];
                sumg = res_monitors[vertex];
            }else{
                sumd = desks[vertex];
                sumg = monitors[vertex];
                for(ll n:G[vertex]){
                    sumd += desks[n];
                    sumg += monitors[n];
                }
            }
            if(sumd == sumg){
                printf("same\n");
            }else if(sumd > sumg){
                printf("desks\n");
            }else{
                printf("monitors\n");
            }
        }
    }
    return 0;
}
