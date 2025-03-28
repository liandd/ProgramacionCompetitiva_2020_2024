#include<bits/stdc++.h>
using namespace std;
bool cmp(const string& a, const string& b) {
    return a.size() < b.size();
}

int LCS_longit(vector<string> a){
    int tam = a.size(); 

    vector<int> dp(tam, 1);
    sort(a.begin(), a.end(), cmp);
    int mx = 1;
    for(int i=1; i < tam; i++){
        for(int j=0; j < i; j++){
            if(a[i].find(a[j]) != string::npos){
                dp[i] = max(dp[i],dp[j]+1); 
                mx = max(mx, dp[i]);
            }
        }
    }

    return mx;
}

int main(){
    int n = 0;
    
    while(cin>> n && n){
        vector <string> w(n);
        int longitud = 0;
        for(int i = 0; i < n; ++i){
            cin>> w[i];
        }
        
        cout<<LCS_longit(w)<<"\n";
    }
}