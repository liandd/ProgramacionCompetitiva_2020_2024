#include<bits/stdc++.h>
using namespace std;

int main(){
    string str;
    cin >> str;
    transform(str.begin(), str.end(), str.begin(), ::tolower);
	
    unordered_set<char> pal = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};
    vector<char> objetivo(str.begin(), str.end()); //copia
    bool arriba = true, abajo = true;

    for (int i = 0; i < str.size() - 1; i++) {
        char actual = objetivo[i];
        char sig = objetivo[i + 1];
        if (pal.find(actual) == pal.end()) continue;

        if (actual > sig) {
            arriba = false;
        }
        if (actual < sig) {
            abajo = false;
        }
    }

    if (arriba || abajo) {
        cout << "yes\n";
    } else {
        cout << "no\n";
    }
    return 0;
}
