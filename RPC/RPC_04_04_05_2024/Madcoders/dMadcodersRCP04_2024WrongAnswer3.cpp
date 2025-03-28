#include <bits/stdc++.h>

using namespace std;

bool es_vocal(char c) {
    return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');
}


string combinar_palabras(const string& primera, const string& segunda) {
    string parte_primera = "";
    string parte_segunda = "";

    parte_primera += primera[0];


    int i = 1;
    for (; i < primera.length(); ++i) {
        if (es_vocal(primera[i])) {
            parte_primera += primera.substr(1, i - 1);
            break;
        }
    }
    if (i == primera.length()) {
        parte_primera += primera.substr(1);
    }


    parte_segunda += segunda.back();
    int j = segunda.length() - 2;
    for (; j >= 0; --j) {
        parte_segunda = segunda[j] + parte_segunda;
        if (es_vocal(segunda[j])) {
            break;
        }
    }
    if (j < 0) {
        parte_segunda = 'o' + parte_segunda;
    }


    return parte_primera + parte_segunda;
}

int main() {
    string primeraPalabra, segundaPalabra;
    cin >> primeraPalabra >> segundaPalabra;

    cout << combinar_palabras(primeraPalabra, segundaPalabra) << endl;

    return 0;
}
