#include<bits/stdc++.h>

using namespace std;

int mcd(int a, int b){
	if(a<b)return mcd(b,a);
	if(b==0)return a;
	return mcd(b,a % b);
}

int main(){
	int t,w,l;
	cin>>t;
	
	while(t--){
		set<int> v;
		cin>>w>>l;
		if(w%2==0&&l%2!=0||w%2!=0&&l%2==0)v.insert(2);
		
		int k1=mcd((w-1),(l-1));
		int k2=mcd(l,(w-2));
		int k3=mcd(w,(l-2));
		
		for(int i=1; i<=sqrt(k1); i++){
			if(k1%i==0){
				v.insert(i);
				v.insert(k1/i);
			}
		}
		
		for(int i=1; i<=sqrt(k2); i++){
			if(k2%i==0){
				v.insert(i);
				v.insert(k2/i);
			}
		}
	
		for(int i=1; i<=sqrt(k3); i++){
			if(k3%i==0){
				v.insert(i);
				v.insert(k3/i);
			}
		}
		cout<<v.size();
		for(auto i: v){
			cout<<" "<<i;
		}
		
		cout<<"\n";
	}
	return 0;

}

