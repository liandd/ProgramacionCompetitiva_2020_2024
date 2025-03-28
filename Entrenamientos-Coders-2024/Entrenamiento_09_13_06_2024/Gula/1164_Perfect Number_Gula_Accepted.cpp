#include <bits/stdc++.h>

using namespace std;
bool buscar(int v[], int x){
	for(int i=0; i<7; i++){
		if(v[i]==x){
			return true;
		}
	}
	return false;
}


int main() {
	int v[]={6,28,496,8128,550336,438691328,589869056};
	int n,x;
	scanf("%d",&n);
	for(int i=0; i<n; i++) {
		scanf("%d",&x);
		if(buscar(v,x)) {
			cout<<x<<" eh perfeito\n";
		} else {
			cout<<x<<" nao eh perfeito\n";
		}
	}

	return 0;
}
