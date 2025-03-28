#include<bits/stdc++.h>
using namespace std;
int main(){
    string str;
    cin>>str;

    sort(str.begin(), str.end());

    str.erase(unique(str.begin(), str.end()), str.end());
    cout<<str.size()-1<<"\n";

    return 0;
}
