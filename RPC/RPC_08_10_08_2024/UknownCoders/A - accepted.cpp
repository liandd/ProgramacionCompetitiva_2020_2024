#include<bits/stdc++.h>
using namespace std;
int main(){
    string str;
    cin>>str;
    transform(str.begin(), str.end(), str.begin(), ::tolower);
    string str2=str;

    sort(str.begin(), str.end());
    string str3=str;
    reverse(str3.begin(), str3.end());
    //cout<<str<<" "<<str2<<" "<<str3;
    if(str==str2 || str2==str3){
        cout<<"yes\n";
    }else{
        cout<<"no\n";
    }
    return 0;
}
