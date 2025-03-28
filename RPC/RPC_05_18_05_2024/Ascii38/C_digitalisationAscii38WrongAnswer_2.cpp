#include<bits/stdc++.h>
using namespace std;
#define F first
#define S second

struct opt{
	int a, b;
};
int main(){
	int n, m, c;
	cin>>n>>m>>c;
	vector<opt> opts(n);
	map<int,int> vp;
	//fill(vp.begin().S,vp.end().S,c);
	//iota(vp.begin().F,vp.end().F,1);
	for(int i=0; i<m; i++){
		vp[i+1]=c;
	}

	for(int i=0;i<n;i++){
		cin>>opts[i].a>>opts[i].b;
	}
	int conta = 0 ,contb = 0;
	int i=0;

while(i <= n){
		if(vp[opts[i].a] == 0 && vp[opts[i].b] == 0) break;
		
		if(vp[opts[i].a] > 0){
			conta++;
			vp[opts[i].a]--;	
		}else if(vp[opts[i].b] > 0){
			contb++;
			vp[opts[i].b]--;
		}
	i++;	
}
cout<< conta << " " << contb <<"\n";
	
	
	return 0;
}







