#include<bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(0);
#define lli long long int
using namespace std;

int main (){
	fast
	lli c=0;
	lli n=0;
	lli n1=0;
	lli n2=0;
	cin>>c;
	cin>>n;
	
	vector<int>	v(n);

	for(int i=0; i<n; i++){
		
		cin>>v[i];
		
		/*for(int p=1; p<n; p++){
			if(v[i]*v[p]==c){
				n1=v[i];
				n2=v[p];
				break;
			}
			
		}*/
		
	}
	
	sort(v.begin(), v.end());
	
	for(int i=0; i<n; i++){
		for(int p=i+1; p<n; p++){
			if(v[i]*v[p]==c){
				n1=v[i];
				n2=v[p];
				break;
			}
				
		}	
	}
	
	
	cout<<n1<<" "<<n2<<"\n";
	return 0;
}
