#include<bits/stdc++.h>

using namespace std;

int main(){
    unsigned long long n, c, d, cc, cd;
    cin>>n;
    while(n--){
        cin>>c>>d;
        if(c || d){
            cc=pow(26,c);
            cd=pow(10,d);
            cout<<cc*cd<<endl;
        }else cout<<0<<endl;

    }


return 0;
}
