#include <bits/stdc++.h>

using namespace std;

int main()
{

    int n, f;
    bool h=false;

    cin>>n>>f;
    vector<int>v(n);

    for(int i=0;i<n;i++){
        cin>>v[i];
    }

    sort(v.begin(), v.end());

    reverse(v.begin(),v.end());

    for(int i=f;i<n;i++){

        if(v[i]>=v[i-f]){
            h=true;
            cout<<"no\n";
            break;
        }
    }

    if(h==false){
        cout<<"yes\n";
    }

    return 0;
}
