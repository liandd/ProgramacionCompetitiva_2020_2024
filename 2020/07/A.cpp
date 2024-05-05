#include <bits/stdc++.h>

using namespace std;

int main(){
    int n, leds = 0;
    cin>>n;
    while(n != 0){
        if(n == 4){
            leds += 4;
            n -= 4;
        }
        if(n >= 3){
            n -= 3;
            leds += 7;
        }
        if(n == 2){
            leds += 1;
            n -= 2;
        }
    }
    cout<<leds<<endl;
    return 0;
}