#include<bits/stdc++.h>
using namespace std;

int main(){
	int n=0, m=0;
	cin>>n>>m;
	vector<int> arr(n);	
	int mat=-1;
	int cont=-1;
	for(int i=0; i<n; i++){
		cin>>arr[i];
	}
	deque<int> dq;
    for(int i=0; i<n; i++){
        if(!dq.empty() && dq.front() < i - m){
            dq.pop_front();
        }
        if(!dq.empty()){
           cont = max(cont, arr[i] - arr[dq.front()]);
        }
        while(!dq.empty() && arr[dq.back()] >= arr[i]){
            dq.pop_back();
        }

        dq.push_back(i);
    }
    cout<<cont<<"\n";
	//TLE
	/*
	for(int i=0; i<n;i++){
		for(int j=i;j<=i+m && j<n;j++){
			mat = arr[j] - arr[i];
			cont=max(cont,mat);
		}
	
	}
	cout<<cont<<"\n";
	*/
	return 0;
}
