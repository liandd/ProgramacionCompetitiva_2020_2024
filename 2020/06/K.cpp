#include <bits/stdc++.h>
using namespace std;

int solve(string a, string b){
	if(a.length() != b.length()) return 3;
	if(a == b) return 1;
	
	int ver = -1;
	for(int i = 0; i < a.length(); i++){
		if(a[i] == b[i]){
			ver++;
		}else if(a[i] < b[i]){
			char der = a[i] + 1, digInfDer = a[i] + 10, abajo = a[i] + 9, digInfIzq = a[i] + 8;
			if(b[i] == der || b[i] == digInfDer || b[i] == abajo || b[i] == digInfIzq) ver++;
		}else if(a[i] > b[i]){
			char der = a[i] - 1, digInfDer = a[i] - 10, abajo = a[i] - 9, digInfIzq = a[i] - 8;
			if(b[i] == der || b[i] == digInfDer || b[i] == abajo || b[i] == digInfIzq) ver++;
		}
		if(ver != i) return 3;
	}
	return 2;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	int n;
	cin>>n;
	
	vector<int> salida;
	for(int i = 0; i < n; i++){
		string a, b;
		cin>>a>>b;
		salida.push_back(solve(a, b));
	}
	
	for(int i = 0; i < salida.size(); i++) cout<<salida[i]<<'\n';
	return 0;
}
