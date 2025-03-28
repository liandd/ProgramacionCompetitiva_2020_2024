#include <bits/stdc++.h>

using namespace std;
int main(){
	
	int cont=4;
	int n;//num matriz
	int m;//filas y colum
	cin>>n;
	while(n--){
		
		cin>>m;
		vector<long long>ss;
		for(int i=0; i<m*m; i++){
			long long num;
			cin>>num;
			num=pow(num,2);
			ss.push_back(num);
		}
		cout<<"Quadrado da matriz #"<<cont<<":\n";	
		for(int i=0; i<m*m;i++){
			
			if(i==m-1 || i==m*m-1){
				cout<<ss[i]<<"\n";
			}else{
				cout<<ss[i]<<" ";
			}
		}
	
		
		cont++;
		
	}
	
	
	
	
	
	
	return 0;
}