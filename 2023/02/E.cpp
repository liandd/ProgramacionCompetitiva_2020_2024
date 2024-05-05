#include<bits/stdc++.h>
using namespace std;
#define PI 3.1415926535897932384626
int main(){

	ios::sync_with_stdio(0);
	cin.tie(0);
	double a=0,r=0,p=0;

	cin>>a;
	r=sqrt(a/PI);
	p=2*r*PI;

    cout<<fixed;
	cout<<setprecision(9)<<p<<"\n";

	return 0;
}
