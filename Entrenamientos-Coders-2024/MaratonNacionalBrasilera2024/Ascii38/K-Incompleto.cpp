#include<bits/stdc++.h>
using namespace std;

void shuffle(int a[], int n){
    for (int i = 0; i < n; i++)
        swap(a[i], a[rand() % n]);
}

void bogo(int a[], int n){ 
    shuffle(a, n);
}

int main(){
	int n = 0;
	cin>>n;
	int arr[n];
	int sum = 0;
	int a = 0, b = 0;
	for(int i = 0; i < n; i++){
		cin>>arr[i];
		sum += arr[i];
	}
	if(sum%2 != 0){
		cout<<-1<<"\n";
		return 0;
	}
	a=arr[0];
	
	while(a!=b){
	
	
	for(int i=1; i<n; i++){
		if(a>b){
			b=b+arr[i];
		} else{
				a=a+arr[i];
			
		}
	}//for
	bool sorner = false;
	if(a==b){
		for(int i = 0; i < n -1 ; i++){
			cout<<arr[i]<<" ";
			sorner=true;
		}
		cout<<arr[n-1]<<"\n";
		break;
	}
	else{
		bogo(arr,n);
		a=0;
		b=0;
	}	
}//while
	return 0;
}
