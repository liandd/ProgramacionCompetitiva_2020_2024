#include <bits/stdc++.h>

using namespace std;

int main(){
    int a, b, c;
    cin>>a>>b>>c;
    while(c--){
        int r, h;
        cin>>r;
        if(r <= 1000){
            h = r * a;
        }else{
            r -= 1000;
            h = (r * b) + (1000 * a);
            r += 1000;
        }
        cout<<r<<" "<<h<<endl;
    }
    return 0;
}