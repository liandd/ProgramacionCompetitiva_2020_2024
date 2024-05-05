#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

int con = 0;

void BFS(int start, vector< vector<int> > g, vector<bool> &used){
	used[start] = true;
	con++;
	for(int i = 0; i < g[start].size(); i++) {
        if(!used[g[start][i]]){
            BFS(g[start][i], g, used);
        }
	}
}

int mcd(int a, int b){
	if(b == 0){
		return a;
	}
	return mcd(b, a % b);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
	int pc, q; cin>>pc>>q;
	vector< vector<int> > g(pc);

	while(q--){
		int aux;
		cin>>aux;
		if(aux == 1){
			int a, b;
			cin>>a>>b;
			a--; b--;
			g[a].push_back(b);
			g[b].push_back(a);
		}else{
		    vector<bool> used(pc, false);
		    int conModu = 0, tot = 0;
		    for(int i = 0; i < pc; i++){
                con = 0;
                if(!used[i]){
                    BFS(i, g, used);
                    conModu++;
                }
                tot += (con * con);
		    }
            int z = mcd(tot, conModu);
            cout<<(tot / z)<<"/"<<(conModu / z)<<endl;
		}
	}
	return 0;
}
