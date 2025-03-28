#include <bits/stdc++.h>
using namespace std;

int main() {
    string a, b, res;
    string v1="", v2="";

    cin>>a>>b;

    vector<char> p1;
    vector<char> p2;
    p1.push_back(a[0]);
    for(int i=1; i<a.size(); i++){
        if(a[i] != 'a'&& a[i] != 'e' && a[i] != 'i' && a[i] != 'o' && a[i] != 'u'){
            p1.push_back(a[i]);
        }else{
            v1=a[i];
            break;
        }
    }
    p2.push_back(b[b.size()-1]);
    for(int i =b.size()-2; i >=0; i--){
        if(b[i] != 'a'&& b[i] != 'e' && b[i] != 'i' && b[i] != 'o' && b[i] != 'u'){
            p2.push_back(b[i]);
        }else{
            v2=b[i];
            break;
        }
    }

    for(auto x: p1)cout<<x<<"-";
    cout<<endl;
    for(auto x: p2)cout<<x<<"-";
    cout<<endl;
    cout<<v1<<"-"<<endl;
    cout<<v2<<"-"<<endl;

    if(v2 != ""){
        for(int i=0; i<p1.size(); i++){
            res+= p1[i];
        }
        res+=v2;
        for(int i=p2.size()-1; i>=0; i--){
            res+=p2[i];
        }
    }else if(v1 != ""){
        for(int i=0; i<p1.size(); i++){
            res+= p1[i];
        }
        //res+=v1;
        for(int i=p2.size()-1; i>=0; i--){
            res+=p2[i];
        }
    }else {
        for(int i=0; i<p1.size(); i++){
            res+= p1[i];
        }
        res+="o";
        for(int i=p2.size()-1; i>=0; i--){
            res+=p2[i];
        }
    }

    cout<<res<<"\n";

    return 0;
}
