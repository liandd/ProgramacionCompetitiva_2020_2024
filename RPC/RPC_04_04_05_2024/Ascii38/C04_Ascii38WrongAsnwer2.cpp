#include<bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(0);cin.tie(0);
int main(){
    fast
    
    int n=0;
    cin>>n;
    
    int arr[n];
    
    for(int i=0; i<n; i++){
    	
    	cin>>arr[i];
    	
	}
	
	int m=-1;
	int c=0;
	  
	for(int i=0; i<n-1; i++){
		
		if(arr[i]<arr[i+1]){          
			c++;
			if(c>m){
				
			m = c;	
				
			}
			
		} else {
			c=0;
			
		}

	}
		cout<<m+1<<"\n";

    return 0;
}

