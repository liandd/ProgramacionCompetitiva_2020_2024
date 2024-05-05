#include<bits/stdc++.h>
using namespace std;
#define fo(i,n) for(int i=0;i<n;++i)
#define pb push_back
typedef vector<int>		vi;


int main(){

	ios::sync_with_stdio(0);cin.tie(0);
  int n;
  string s;
  cin>>n>>s;
  vi a(n+1);
  fo(i,n){
    int xs=(s[i]=='X')? 1:0;
    a[i+1]=a[i]+xs;
  }
  int r=0;
  for(int i=0;i<=n;++i){
    for(int j=3;j*j<=i;++j){
      r+=(a[i]-a[i-j*j]==(j-2)*(j-2)||a[i]-a[i-j*j]==4*(j-1))? 1 : 0 ;
    }
  }
  cout<<r<<"\n";
	return 0;
}

