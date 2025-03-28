#include<bits/stdc++.h>
using namespace std;

#include <iostream>
#include <string>

using namespace std;

bool isVowel(char c) {
    return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');
}

char aux1;
bool aux2 = true;

string combineWords(const string first, const string second) {
    string combinedWord = "";

    combinedWord += first[0];
    for (int i = 1; i < first.length(); ++i) {
        if (isVowel(first[i])) {
            combinedWord += first.substr(1, i - 1);
            aux1 = first[i];
            aux2 = false;
            break;
        }
    }
    if (aux2) {
        combinedWord += first.substr(1);
        char mergingVowel = 'o';
        combinedWord += mergingVowel;
        combinedWord += second;
    }else {
        bool aux = false;
		for (int i = 1; i < second.length(); ++i) {
			if (isVowel(second[i]) && aux == false) {
				combinedWord += second.substr(i);
				aux = true;
				break;
			}
			if ( aux ){
				combinedWord += second.substr(i);
			}
		}
		if ( !aux ) {
			combinedWord += aux1;
			combinedWord += second;
		}
    }
    
    
    return combinedWord;
}

int main() {
    string firstWord, secondWord;
    cin >> firstWord >> secondWord;

    cout << combineWords(firstWord, secondWord) << endl;

    return 0;
}

