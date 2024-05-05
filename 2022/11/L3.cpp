#include<bits/stdc++.h>

using namespace std;

bool valid(string a,char b){
	
	for(int i=0;i<a.size();i++){
		if(a[i]==b)return true;
	}
	return false;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	char l[64];
	char t[64];
	char g[64];
	char r[6];
	
	

	cin>>l;
	for(int i=0;i<7;i++){
	int c=0;
		cin>>g;
		if(g==NULL){
		cout<<"LOSER\n";
		break;
		}
		for(int j=0; j<5; j++){
			if(l[j]==g[j]){
				c++;
				r[j]='G';
				t[j]='.';
				g[j]='.';
			}else{
				t[j]=l[j];
				r[j]='X';
			}
		}
		if(c==5){
			cout<<"WINNER\n";
			break;
		}
		if(i==6){
			cout<<"LOSER\n";
			break;
		}
		for(int j=0;j<5;j++){
			if(g[j]!='.'&&valid(l,g[j])){
				r[j]='Y';
			}
		}
		cout<<r<<"\n";
	}
	
	
return 0;	
}
