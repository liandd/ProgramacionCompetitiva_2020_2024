#include<bits/stdc++.h>

using namespace std;

long long int gcd(long long int a, long long int b){
	if(a<b){
		return gcd(b,a);
	}else if(b==0){
		return a;
	}
	return gcd(b,a%b);
}

int main(){
	int n=0;
	int datos=32;
	long long int dg[datos];
	
	long long int nu[datos];
	long long int de[datos];
	
	long long int cn =3;
	long long int cd =2;
	long long int sum=0;
	
	int c;
	long long int w,r,d;
	while((c = getc(stdin))>= '0' && c <= '2'){
		if(n==0){
			nu[0]=1;
			de[0]=1;
		}else{
			nu[n]=cn;
			de[n]=cd;
			cn*=3;
			cd*=2;
		}
		dg[--datos]=(long long int) (c-'0');
		n++;
	}
	cd=de[n-1];
	
	for(int i=0;i<n;i++){
		nu[i]=nu[i]*(cd/de[i]);
		sum+=nu[i]*dg[datos+i];
	}
	w=sum/cd;
	r=sum%cd;
	cout<<w;
	if(r!=0){
		d=gcd(r,cd);
		cout<<" "<<(r/d)<<"/"<<(cd/d);
	}
	cout<<"\n";
	return 0;
	
}
