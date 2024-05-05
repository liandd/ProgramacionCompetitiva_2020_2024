#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, res;
    cin>>n;

    vector<long long> arr(n);
    res = n;
    for(int i = 0; i < n; i++) cin>>arr[i];

    for(int i = 0; i < n; i++){
        int aux = 0, cant = 0;
        set<unsigned long long> v;
        for(int j = i; j < n; j++){
            v.insert(arr[j]);
            cant++;
            if(v.size() == cant) res++;
            else break;
        }
        res--;
    }

    cout<<res<<"\n";
    return 0;
}
