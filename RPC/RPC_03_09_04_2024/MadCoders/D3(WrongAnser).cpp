#include<bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    
    int contador = 0;
    
    for (int i = 1; i * i <= n; i++) {

        if (n % i == 0) {
            if (i * i == n) {
                contador++;
            } else {
                contador += 2;
            }
        }
    }
    
    if( contador % 2 == 0){
        cout<< "Y";
    }else {
        cout<<"N";
    }
    
    return 0;
}