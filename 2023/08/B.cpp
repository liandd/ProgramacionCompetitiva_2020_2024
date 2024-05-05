#include <bits/stdc++.h>
using namespace std;

bool isVowel(char c) {
    return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
}

bool isEasyToPronounce(string word) {
    int length = word.length();
    for (int i = 0; i < length - 1; i++) {
        if (isVowel(word[i])) {
            if (!isVowel(word[i + 1])) {
                continue;
            } else {
                return false;
            }
        }
        if (!isVowel(word[i])) {
            if (isVowel(word[i + 1])) {
                continue;
            } else {
                return false;
            }
        }
    }
    return true;
}

int main() {
    string word;
    cin >> word;

    if (isEasyToPronounce(word)) {
        cout << "1\n";
    } else {
        cout << "0\n";
    }

    return 0;
}
