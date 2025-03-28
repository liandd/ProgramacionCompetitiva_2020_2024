#include <bits/stdc++.h>
using namespace std;

int main()
{
    int k,n,m,x,y;
    string res ="";

    while(cin>>k && k != 0){
        cin>>n>>m;
        for(int i =0;i< k;i++){
            cin>>x>>y;
            if(x == n || y == m){
                cout<<"divisa"<<"\n";
            }else{
                res=(y>m)?res+"N":res+"S";
                res=(x>n)?res+"E":res+"O";
                cout<<res<<"\n";
            }
            res="";
        }

    }

    return 0;
}
