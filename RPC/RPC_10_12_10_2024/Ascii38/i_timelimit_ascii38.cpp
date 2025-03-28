#include<bits/stdc++.h>
using namespace std;


int count(int x, int y){


	
	
	
}//count




int main(){

int rooms=0, query=0;
cin>>rooms>>query;

bool rh[rooms+1];

for(int i=1; i<=rooms; i++){
rh[i]=true;	
}//for
	
while(query--){
int c=0;
char morcilla =' ';	
cin>>morcilla;

if(morcilla=='A'){
int x=0, y=0;
cin>>x>>y;	

for(int i=x; i<=y; i++){
	
	if(rh[i]==true){
	c++;
	}
	
	
}//for	

cout<<c<<"\n";
c=0;
	
} else{
	
int sorner;
cin>>sorner;
rh[sorner]=false;	
	
}	
	
	
	
}//while	
	
	
	
	
	
	
	
	
	
}
