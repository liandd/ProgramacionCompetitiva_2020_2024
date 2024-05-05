#include<bits/stdc++.h>
using namespace std;

int main(){
	
	long long n;
	cin >> n;
	int cont=0;
	
	for(int i = 1; i< 10; i++){
		long long num = i;
		while(num <= n){
			num= num*10+i;
			cont++;
		}
	}
	
	cont++;
	long long num = 100;
	while(num <= n){
		num=num*10;
		cont++;
	}
	cout << cont << "\n";
}
