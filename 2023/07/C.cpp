#include<bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;

    vector<string> words(N);
    for (int i = 0; i < N; ++i) {
        cin >> words[i];
    }

    int maxLength = 0;
    for (const string& word : words) {
        maxLength = max(maxLength, static_cast<int>(word.length()));
    }

    vector<vector<int>> frequency(maxLength, vector<int>(26, 0));
    for (const string& word : words) {
        for (int i = 0; i < word.length(); ++i) {
            frequency[i][word[i] - 'a']++;
        }
    }

    for (int i = 0; i < maxLength; ++i) {
        vector<char> maxLetters;
        int maxCount = 0;

        for (int j = 0; j < 26; ++j) {
            if (frequency[i][j] > maxCount) {
                maxLetters.clear();
                maxLetters.push_back('a' + j);
                maxCount = frequency[i][j];
            } else if (frequency[i][j] == maxCount) {
                maxLetters.push_back('a' + j);
            }
        }

        cout << (i + 1) << ": ";
        sort(maxLetters.begin(), maxLetters.end());
        for (int j = 0; j < maxLetters.size(); ++j) {
            cout << maxLetters[j];
            if (j < maxLetters.size() - 1) {
                cout << " ";
            }
        }
        cout << "\n";
    }

    return 0;
}
