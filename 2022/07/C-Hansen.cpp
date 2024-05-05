#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main()
{
    
    string c1="";
    string c2="";
    int total=1;
    
    cin>>c1;
    cin>>c2;
    
    for(int i=0; i<c1.size();i++){
    	
    	if(c1[i]==c2[i]){
    		total*=1;
		}
		
		else{
			total*=2;
		}
    	
	}
	
	cout<<total<<endl;
    

    return 0;
}
