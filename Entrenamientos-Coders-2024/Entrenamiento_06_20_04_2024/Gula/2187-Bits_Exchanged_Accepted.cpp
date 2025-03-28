#include <bits/stdc++.h>
using namespace std;
int main (){

int valor = 0, cont = 1,B50 = 0, B10 = 0, B5 = 0, B1 = 0;

    while (cin >> valor && valor != 0) {

        cout << "Teste " << cont++ << "\n";

        B50 = valor/50;
        valor %= 50;

        B10 = valor/10;
        valor %=10;

        B5 = valor/5;
        valor %= 5;
        B1 = valor;


        cout << B50<< " " << B10 << " " << B5 << " " << B1 << "\n";
        cout << "\n";
    }
return 0;
}
