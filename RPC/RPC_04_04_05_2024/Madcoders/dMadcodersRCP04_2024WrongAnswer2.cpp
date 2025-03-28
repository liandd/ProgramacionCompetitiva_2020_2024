#include<bits/stdc++.h>

using namespace std;

bool vocales(char c) {
    return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');
}

char vocalFusion;
bool encontroVocal = true;

string combinar_palabras(const string primera, const string segunda) {
    string palabra_combinada = "";

    palabra_combinada += primera[0];
    for (int i = 1; i < primera.length(); ++i) {
        if (vocales(primera[i])) {
            palabra_combinada += primera.substr(1, i - 1);
            vocalFusion = primera[i];
            encontroVocal = false;
            break;
        }
    }
    if (encontroVocal) {
        palabra_combinada += primera.substr(1);
        char vocalFusion = 'o';
        palabra_combinada += vocalFusion;
        palabra_combinada += segunda;
    } else {
        bool encontro_vocal_segunda = false;
        for (int i = 1; i < segunda.length(); ++i) {
            if (vocales(segunda[i]) && !encontro_vocal_segunda) {
                palabra_combinada += segunda.substr(i);
                encontro_vocal_segunda = true;
                break;
            }
            if (encontro_vocal_segunda) {
                palabra_combinada += segunda.substr(i);
            }
        }
        if (!encontro_vocal_segunda) {
            palabra_combinada += vocalFusion;
            palabra_combinada += segunda;
        }
    }

    return palabra_combinada;
}

int main() {
    string primeraPalabra, segundaPalabra;
    cin >> primeraPalabra >> segundaPalabra;

    cout << combinar_palabras(primeraPalabra, segundaPalabra) << endl;

    return 0;
}
