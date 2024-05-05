#include <bits/stdc++.h>

using namespace std;

int main(){
	
	int n, s, b, m;

	cin>>n;
	int cont=0;
	
	while(n--){
		
		cin>>s>>b;
		cin>>m;
		
		vector <int> alumnos(m);
		
		for(int i=0; i<alumnos.size(); i++){
			cin>>alumnos[i];			
		}
	
		cout<<"Practice #"<<cont+1<<": "<<s<<" "<<b<<"\n";
	
		int restante=b;
	
		for(int i=0; i<alumnos.size();i++){
			
			if(restante<alumnos[i]){
				
				do{
					
					restante=restante*2;
					
				}while(restante<=alumnos[i]);
				
			}
			restante= restante-alumnos[i];
			
			if(restante==0){
				
				cout<<alumnos[i]<<" "<<restante+alumnos[i]<<"\n";
				
			}
			else{
				cout<<alumnos[i]<<" "<<restante<<"\n";
			}
			
		}
		
	}
	
    return 0;
    
}








