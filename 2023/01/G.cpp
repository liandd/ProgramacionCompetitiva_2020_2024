#include <bits/stdc++.h>
using namespace std;
int factorial[]={1,1,2,6,24,120,720,5040,40320,362880};
int f(int x){
    if(x==0){
        return 1;
    }
    int suma=0;
    while(x>0){
        suma +=factorial[x%10];
        x/=10;
    }
    return suma;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int y=0;
    cin>>y;
    int k=9;
    stringstream oss;
    while(y>0){
        while(y<factorial[k]){
            k--;
        }
        oss << k;//oss*oss(k^k)
        y -= factorial[k];
    }
    string outStr = oss.str ();
    if (outStr == "1") {
        outStr = "0";
    }
    for (auto it = outStr.rbegin(); it != outStr.rend(); it++) {
        cout << *it;
    }
    cout << "\n";
    return 0;
}
