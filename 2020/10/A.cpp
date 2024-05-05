#include <bits/stdc++.h>

using namespace std;

int main(){
	int n;
	cin>>n;
	set<string> cumples;
	
	for(int i = 0; i < n; i++){
		string aux;
		cin>>aux;
		cumples.insert(aux);
	}
	cout<<cumples.size()<<endl;
	return 0;
}