#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, suma = 0;
    cin>>n;

    for(int i = 0; i < n; i++){
        int aux;
        cin>>aux;

        suma += aux;
    }

    int res = suma / 3;

    cout<< ( res * 3  == suma ? "yes\n" : "no\n") ;
    return 0;
}
