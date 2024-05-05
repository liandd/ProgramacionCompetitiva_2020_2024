#include <bits/stdc++.h>
using namespace std;

struct lista{
	bool x;
	string name;
	int next;
};

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	string f;
	getline(cin, f);
	int song = 0;
	for(int i = 0; i < f.length(); i++) if(f[i] == ' ') song++;
	int n;
	cin>>n;
	cin.ignore();
	vector<lista> nombre(n);
	vector<string> a;
	vector<string> b;
	for(int i = 0; i < n; i++){
		cin>>nombre[i].name;
		nombre[i].x = true;
		nombre[i].next = (i + 1) % (n);
	}
	
	int equipo = 0, pos = 0, cont = 0;
	while(a.size() + b.size() < n){
		int i = pos;
		if(nombre[i].x){
			if(cont == song){
				cont = 0;
				nombre[i].x = false;
				if(equipo%2 == 0){
					a.push_back(nombre[i].name);
				}else{
					b.push_back(nombre[i].name);
				}
				equipo++;
			}else{
				cont++;
			}
		}
		pos = nombre[i].next;
	}
	
	cout<<a.size()<<'\n';
	for(int j = 0; j < a.size(); j++) cout<<a[j]<<'\n';
	cout<<b.size()<<'\n';
	for(int j = 0; j < b.size(); j++) cout<<b[j]<<'\n';
	return 0;	
}
