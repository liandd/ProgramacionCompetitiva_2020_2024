#include<bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    
    int contador = 0;
    
    for (int i = 1; i <= n; i++) {

        if (n % i == 0) {
            contador++;
        }
    }
    
    if( contador % 2 == 0){
        cout<< "Y";
    }else {
        cout<<"N";
    }
    
    return 0;
}