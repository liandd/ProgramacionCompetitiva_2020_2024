#include<bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin>>n;
    set<pair<long long int, long long int> > b;
    vector<long long int> data = vector<long long int>( n, 0);
    for(int i = 0; i < n; i++)
        cin>>data[i];
    for(int i = 0; i < n; i++) {
        for(int j = i + 1; j < n; j++) {
            pair<long long int, long long int> x;
            x.first = data[i];
            x.second = data[j];
            b.insert(x);
        }
    }
    cout<<b.size()<<endl;
    return 0;
}
