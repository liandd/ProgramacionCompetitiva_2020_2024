#include <bits/stdc++.h>
using namespace std;

int precedencia(char op) {
    if (op == '+' || op == '-')
        return 1;
    if (op == '*' || op == '/')
        return 2;
    if (op == '^')
        return 3;
    return 0;
}

bool esNumero(char z) {
    if (z != '+' && z != '-' && z != '*' && z != '/' && z != '^' && z != '(' && z != ')') {
        return true;
    }
    return false;
}

string posfija(string pal) {
    string res;
    stack<char> pila;
    for (int i = 0; i < pal.length(); i++) {
        if (esNumero(pal[i])) {
            res += pal[i];
        }
        if (pal[i] == '(') {
            pila.push(pal[i]);
        } else if (pal[i] == ')') {
            while (!pila.empty() && pila.top() != '(') {
                res += pila.top();
                pila.pop();
            }
            if (!pila.empty()) pila.pop(); // sacar '('
        } else if (pal[i] == '+' || pal[i] == '-' || pal[i] == '*' || pal[i] == '/' || pal[i] == '^') {
            while (!pila.empty() && precedencia(pila.top()) >= precedencia(pal[i])) {
                res += pila.top();
                pila.pop();
            }
            pila.push(pal[i]);
        }
    }
    while (!pila.empty()) {
        res += pila.top();
        pila.pop();
    }

    return res;
}

int main() {
    int n;
    string expresion;
    scanf("%d", &n);
    while (n--) {
        cin >> expresion;
        cout << posfija(expresion) << endl;
    }
    return 0;
}
