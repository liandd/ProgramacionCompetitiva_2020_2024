#include<bits/stdc++.h>
using namespace std;

int main(){
	int amper=0;
	int w=0;
	int v=0;
	cin>>amper>>w>>v;
	
	int resultwat = 0, ra = 0;
	resultwat = amper * v;
	ra = w / v;

	if( ra >= amper ){
		cout<<"1\n";
	}
	else{
		cout<<"0\n";
	}
	
	return 0;
}
