#include<bits/stdc++.h>
using namespace std;


int main(){
	
	long int problems=0, solutions=0;
	cin>>problems>>solutions;
	
	bool contest [problems][4];
	
	 for(long int i=1; i<=problems; i++){
  	for(long int j=1; j<=3; j++){	
  		contest[i][j]=false;
  		
	  }
  	
  }//for anidado
	
	
	
	
    for(long int i=0; i<solutions; i++){
    long int auxx=0, auxy=0;
    cin>>auxx>>auxy;
	 contest[auxx] [auxy] = true;		
	}//while
	

	
	for(long int i=1; i<=problems; i++){
	  if(contest[i][1]==true && contest[i][2]==true){
	  	cout<<i<<"\n";
	  	
	  }//if
		
		
		
	}//for
	
	
	
	
	return 0;
	
}
