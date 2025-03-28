#include <bits/stdc++.h>
using namespace std;

int main(){
	int a, b;
	while(cin>>a>>b) {
		int casas=0;
	
		for(int i=a; i<=b; i++){
			
			string num= to_string(i);
			set <char> rep;
			bool rep2=false;
			
			 			
			for(int j=0; j<num.size(); j++){
				
				if(rep.find(num[j]) != rep.end()){
					rep2=true;
					break;
				}else{
					rep.insert(num[j]);
				}	
			}
			
			if(!rep2){
				casas++;
			}
			rep.clear();
		}
		
		cout<<casas<<"\n";
	}
		
	return 0;
}