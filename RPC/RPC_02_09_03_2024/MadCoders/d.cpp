#include<bits/stdc++.h>

using namespace std;

string getCountyName(int n, int m, vector<string>& cityNames) {
    string countyName = "";

    for (int i = 0; i < m; ++i) {
        unordered_map<char, int> letterVotes;

        for (const string& city : cityNames) {
            char letter = city[i];
            letterVotes[letter]++;
        }

        char maxLetter = 'a';
        int maxVotes = 0;

        for (const auto& entry : letterVotes) {
            if (entry.second > maxVotes || (entry.second == maxVotes && entry.first < maxLetter)) {
                maxLetter = entry.first;
                maxVotes = entry.second;
            }
        }

        countyName += maxLetter;
    }

    return countyName;
}

int main()
{
    int n, m;
    cin >> n >> m;

    vector<string> cityNames(n);
    for (int i = 0; i < n; ++i) {
        cin >> cityNames[i];
    }

    string result = getCountyName(n, m, cityNames);
    cout << result << endl;

    return 0;
}