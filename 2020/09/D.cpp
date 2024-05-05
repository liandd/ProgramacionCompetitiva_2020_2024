#include<bits/stdc++.h>
using namespace std;

int main(){
	float n, salida;
	cin>>n;
	
	salida = ((n*4) + ((n*0.093185)/0.1)*2);
	salida *= salida;
	cout<<fixed<<setprecision(5)<<salida<<endl;
	return 0;
}