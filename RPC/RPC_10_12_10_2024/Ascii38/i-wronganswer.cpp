#include<bits/stdc++.h>
using namespace std;

int contar(int a, int b){
	int cont=0;
	for(int i=a;i<=b;i++){
		cont++;
	}
	return cont;	
}

int sorner(int a, int b, vector<int>&mat){
	int cont=0;
	for(int i=a;i<=b;i++){
		if(mat[i]!=1){
			cont++;
		}  
	}
	return cont;
}
int main(){
	int n =0, m=0;
	cin>>n>>m;
	vector<int> mat(n,0);
	int VaroomNumber = 0, endRoom = 0, startRoom = 0;
	int cont = 0;
	bool r = false;
	char x;
	while(m--){
		cin>>x;
		if(x=='A'){
			cin>> VaroomNumber>>endRoom;
			
			if(r){
				cout<<sorner(VaroomNumber,endRoom, mat)<<endl;
			
			}else{
				cout<<contar(VaroomNumber,endRoom)<<endl;
				
			}
			r=false;

		}else{
			cin>>startRoom;
			mat[startRoom-1]=1;
			r=true;
			startRoom=0;
			
		}	
	}
	return 0;
}
