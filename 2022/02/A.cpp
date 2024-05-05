#include <bits/stdc++.h>
using namespace std;

int main(){
    long long a, b;
    cin>>a>>b;
    int steps = 0;
    while(a != b){
        if(a < b){
            int dif = b - a;
            steps += dif;
            a += dif;
        }else if(a % 2 == 0){
            steps ++;
            a /= 2;
        }else{
            a++;
            steps++;
        }
    }

    cout<<steps<<'\n';

    return 0;
}
