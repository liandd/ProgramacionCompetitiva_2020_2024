#include <bits/stdc++.h>

using namespace std;

int main(){
    int initial_a, initial_b, actual, steeps = 2, a, b;
    cin>>initial_a>>initial_b;
    a = initial_a;
    b = initial_b;
    
    while(true){
        steeps ++;
        actual = (a + b) % 10;
        if( b == initial_a && actual == initial_b ){
            cout<< steeps << '\n';
            return 0;
        }
        a = b;
        b = actual;
    }
    
    return 0;
}

