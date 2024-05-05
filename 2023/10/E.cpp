#include<bits/stdc++.h>
using namespace std;
#define fo(i,n) for(int i=0;i<n;i++)
#define F first
#define S second
typedef pair<int, int>	pii;
typedef vector<pii>		vpii;
typedef vector<int>		vi;

int main(){

	ios::sync_with_stdio(0);cin.tie(0);
	int n;
	cin>>n;
	set<vpii>formas;
	fo(i,n){
	    int m;
	    cin>>m;
	    vpii forma(m);
	    fo(j,m){
	        cin>>forma[j].F>>forma[j].S;
	    }
	    sort(forma.begin(),forma.end());
	    int minx = forma[0].F, miny = forma[0].S;
	    fo(j,m){
	        forma[j].F -= minx;
	        forma[j].S -= miny;
	    }
	    formas.insert(forma);
	}
	cout<<formas.size()<<"\n";
	return 0;
}
