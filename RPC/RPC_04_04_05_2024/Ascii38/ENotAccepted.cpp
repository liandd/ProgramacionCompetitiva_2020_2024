#include<bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(0);cin.tie(0);
int main(){
    fast
int s1=0, s2=0;

cin>>s1>>s2;
int ar[s1];
vector<pair<int,int>> h(s1-s2+1);

for(int i=0; i<s1; i++){
cin>>ar[i];
}
int n=1;
for(int i=0, s=1; i<s1-s2+1; i++, s++){
n=0;
for(int j=1, k=i; j<=s2; j++,k++){
n+=(j*ar[k]);
}
h[i].first={n};
h[i].second={s};
cout<<h[i].second<<" "<<h[i].first<<"\n";
}

sort(h.begin(), h.end());

for(int i=0; i<s1-s2+1; i++){
cout<<h[i].second<<" "<<h[i].first<<"\n";
}

    return 0;
}