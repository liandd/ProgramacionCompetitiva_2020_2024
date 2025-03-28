#include<bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;

    if (N == 0 || N == 1) {
        cout << 0 << endl;
        return 0;
    }

    string secuencia;
    cin >> secuencia;

    stack<char> s;
    int contador = 0;

    for (char c : secuencia) {
        if (c == '(') {
            s.push(c);
        } else if (c == ')') {

            if (!s.empty() && s.top() == '(') {

                s.pop();

                contador++;
            }
        }
    }


    if (s.empty()) {
        cout << contador << endl;
    } else {
        cout << contador << endl;
    }

    return 0;
}
