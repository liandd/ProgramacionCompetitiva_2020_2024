#include<bits/stdc++.h>
using namespace std;

int main(){

    ios::sync_with_stdio(0);cin.tie(0);
    int n,x=0,y=0;
    cin>>n;

    for(int i=0;i<n;++i){
       string w;
       cin>>w;
       int pos=w.find('-');
       int a=stoi(w.substr(0,pos));
       int b=stoi(w.substr(pos+1));
        if((a+b)%4==1||(a+b)%4==2){
            swap(a,b);
        }

        if(a < x || b < y || a > 11 || b > 11 || (a == 11 && b == 11)
        || ((x == 11 || y == 11) && (x != a || y != b))) {
            cout<<"error " << i+1 << endl;
            return 0;
        }
        x = a;
        y = b;
    }
    cout<<"ok\n";
    return 0;
}
