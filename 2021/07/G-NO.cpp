#include <bits/stdc++.h>
using namespace std;

struct team{
	int name;
	int pos;
};

bool cmp(team a, team b){
	return a.pos < b.pos;
}

int main(){
	int n, m;
	cin>>n>>m;
	vector<team> teams(n);
	
	for(int i = 0; i < n; i++){
		team aux;
		aux.pos = i;
		aux.name = i + 1;
		teams[i] = aux;
	}
	cin.ignore();
	for(int q = 0; q < m; q++){
		string query;
		getline(cin, query);
		int a = query[1] - '0';
		int b = query[4] - '0';
		int ta_pos = 0;
		int tb_pos = 0;
		for(int i = 0; i < n; i++){
			if(teams[i].name == a){
				ta_pos = teams[i].pos;
			}
			if(teams[i].name == b){
				tb_pos = teams[i].pos;
			}
		}
		
		if(ta_pos > tb_pos){
			for(int i = 0; i < n; i++){
				if(teams[i].pos < ta_pos && teams[i].pos > tb_pos && teams[i].name != b && teams[i].name != a) teams[i].pos--;
				if(teams[i].name == a){
					teams[i].pos--;
				}
				if(teams[i].name == b){
					teams[i].pos = ta_pos;
				}
			}
		}
	}	
	
	sort(teams.begin(), teams.end(), cmp);
	for(int i = 0; i < n; i++)
		cout<<'T'<<teams[i].name<<' ';
	cout<<'\n';
	return 0;
}
