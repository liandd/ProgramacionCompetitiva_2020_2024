#include<bits/stdc++.h>
using namespace std;
#define fo(i,n) for(int i=1;i<n;++i)
#define pi(x)	printf("%d\n",(x+1)/2)

int main(){

	ios::sync_with_stdio(0);cin.tie(0);
  string k;
  cin>>k;
  int n=k.size(),r=0;
  fo(i,n)
      if(k[i]==k[i-1])
          r++;
  pi(r);

	return 0;
}
