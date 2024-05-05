#include <bits/stdc++.h>
using namespace std;

int main(){
	long long a, b;
	int salida = 0;
	cin>>a>>b;
	
	while(a != b){
		if(a < b){
			a++;
		}else{
			if(a%2 == 0){
				a /= 2;
			}else{
				a++;
			}
		}
		salida++;
	}
	cout<<salida<<'\n';
	return 0;
}

