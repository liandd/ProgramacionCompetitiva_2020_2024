#include<bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(0);cin.tie(0);
int main(){
    fast
	int s1=0, s2=0, s3=0;
	
	cin>>s1>>s2>>s3;
	
	for(int i=1; i<150; i++){
		for(int j=1; j<150; j++){
			if(s1==(s2*i)+(s3*j)){
				cout<<1<<"\n";
				return 0;
			}
		}
	}
	
	cout<<0<<"\n";


    return 0;
}

