#include<bits/stdc++.h>
using namespace std;
#define llu unsigned long long int
int main(){
	llu numero;
	while(cin>>numero){
		if(numero == -1)
			break;
		if(numero == 0)
			cout << "0\n" ;
		else{
			numero -= 1;
			cout << numero <<"\n";
		}
	}
	return 0;
}
