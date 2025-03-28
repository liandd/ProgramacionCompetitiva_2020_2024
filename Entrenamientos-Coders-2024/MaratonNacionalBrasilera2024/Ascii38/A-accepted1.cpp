#include<bits/stdc++.h>
using namespace std;

int main(){
	int n=0;
	int t=0;
	cin>>n>>t;
	if(n==0){
		cout<<0<<"\n";
		return 0;
	}
	if(n==1){
		cout<<t<<"\n";
		return 0;
	}
	if(t==0){
		cout<<t<<"\n";
		return 0;
	}
	else{
		int tmp=0;
		vector<pair<int,int> > arr;
		for(int i=0;i<t;i++){
			tmp=n-1;
			if((tmp+(i*n))<t)
				arr.push_back({tmp,i});
		}
		cout<<arr[arr.size()-1].second<<"\n";
	}
	return 0;
}
