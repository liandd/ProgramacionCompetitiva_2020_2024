#include <bits/stdc++.h>
using namespace std;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	vector<int> arr(100);
	for(int i = 0; i < 100; i += 4){
		arr[i] = 1;
		arr[i + 1] = 2;
		arr[i + 2] = 1;
		arr[i + 3] = 3;
	}
	
	int  n;
	cin>>n;
	
	if(arr[n - 1] == 1) cout<<"Either"<<'\n';
	if(arr[n - 1] == 2) cout<<"Odd"<<'\n';
	if(arr[n - 1] == 3) cout<<"Even"<<'\n'; 
	return 0;
}
