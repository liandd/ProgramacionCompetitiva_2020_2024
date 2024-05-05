#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    vector<int> num (2501);
    for(int i = 1; i <= 2500; ++i){
        int cont = 0;
        for(int j = 1; j <= i; j++){
            if(i % j == 0) cont++;
        }
        num[i] = cont;
    }


    int A;
    cin>>A;
    while(A--){
        int N, pos_mayor = 0, mayor = 0;
        cin>>N;
        for(int i = 1; i <= N; i++){
            if(num[i] > mayor){
                mayor = num[i];
                pos_mayor = i;
            }
        }
        cout<<pos_mayor<<"\n";
    }
    return 0;
}
