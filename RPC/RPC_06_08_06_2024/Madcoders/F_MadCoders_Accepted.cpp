#include <bits/stdc++.h>

using namespace std;

int main(){
    int n, p, aux=0;
    cin>>n>>p;
    while(n--){
        int n1;
        cin>>n1;
        if(n1>aux && n1<=p)aux = n1;
    }
    cout<<aux<<endl;


return 0;
}
