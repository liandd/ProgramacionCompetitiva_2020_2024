#include <bits/stdc++.h>

using  namespace std;

struct pp {
	char op;
	int punt;
	string vv;
	int cont;
} aa;

vector<char> nose(vector<char> ayuda,char xx){
	
	ayuda.push_back(xx);
	
	return ayuda;
}

vector<pp> llenar(vector<pp> res, char s, int punt, string vv) {
	aa.op=s;
	aa.punt=punt;
	aa.vv=vv;
	aa.cont=0;
	res.push_back(aa);

	return res;
}

void cc(vector<pp> res, vector<char> ayuda) {

	int aux=0;
	int cor=0;
	
	int n=0;
	
	for(auto i: ayuda){
		for(auto j: res){
			if( i == j.op && j.vv!="correct"){
				n++;	
			}
		}
	}
	
	for(auto i: res){
		if(i.vv=="correct") {
			aux+=i.punt;
			cor++;
		}
	}
	
	aux+=n*20;

	printf("%d %d\n", cor, aux);


}

int main() {


	bool ban=true;

	while(ban) {

		int s;
		scanf("%d",&s);
		if(s==0) {
			return 0;
		}
		char op;
		int punt;
		string vv;
		vector<pp> res;
		vector<char> ayuda;
		for(int i=0; i<s; i++) {
			cin>>op;
			cin>>punt;
			cin>>vv;
			if(vv=="correct") {
			ayuda=nose(ayuda, op);	
			}
			res=llenar(res, op, punt, vv);
		}
		cc(res,ayuda);
		res.clear();
		ayuda.clear();
	}



	return 0;
}