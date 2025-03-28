#include<bits/stdc++.h>
using namespace std;

int main(){
	
	string p="";
	cin>>p;
	vector<int> numeros(10);
	int r = 0;
	set<int> eco;
	for(int i=0; i<p.size();i++){
		if(p[i] != '-'){
			int aux = p[i] - '0';
			eco.insert(aux);
			aux = 0;
		}
	}
	cout<<eco.size()<<endl;
	return 0;
}
