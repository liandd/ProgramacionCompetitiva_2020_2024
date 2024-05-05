#include <bits/stdc++.h>
using namespace std;

int main(){
	int n;
	cin>>n;
	
	vector<float> arr(n);
	
	for(int i = 0; i < n; i ++) cin>>arr[i];
	
	sort(arr.begin(), arr.end());
	
	float menor = 1;
	for(int i = 0; i < n; i++){
		if(arr[i] > (i + 1)){
			cout<<"impossible"<<endl;
			return 0;
		}
		float aux = arr[i] / (i + 1);
		if(aux < menor){
			menor = aux;
		}
	}
	
	cout<<menor<<endl;
	return 0;
}
