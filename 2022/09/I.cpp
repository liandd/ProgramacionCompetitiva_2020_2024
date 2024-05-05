#include <bits/stdc++.h>
#include <vector>
using namespace std;

int main(){
	
	int n=0;
	cin>>n;
	n=n-1;
	vector<int> vect;
	int x=0;
	int falta=0;
	string imp="";
	
	for(int i=0; i<n; i++){
		cin>>x;
		vect.push_back(x);
	}
	
	sort(vect.begin(), vect.end());
	vect.push_back(vect[n-1]+1);
    
    for(int i=0; i<n-1; i++){	
		
    	if((vect[i]+1)!=vect[i+1] && i<n-1){
    		falta=vect[i]+1;
    		cout<<falta<<endl;
    		break;	
		}else if(i==n-2){
			imp="IMPOSSIBLE";
			cout<<imp<<endl;
		}
		
	} 
	
}
