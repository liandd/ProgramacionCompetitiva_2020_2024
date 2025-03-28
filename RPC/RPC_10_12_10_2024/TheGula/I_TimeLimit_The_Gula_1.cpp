#include <bits/stdc++.h>

using namespace std;

void nn(int n, const vector<string>& t) {
    vector<int> v(n + 1, 0);  
    
    for (const string& i : t) {
        if (i[0] == 'R') {
            int h = stoi(i.substr(2));
            v[h] = 1;  
        } else if (i[0] == 'A') {
            int ini = stoi(i.substr(2, i.find(' ', 2) - 2));
            int fin = stoi(i.substr(i.find(' ', 2) + 1));
            int cont = 0;
            for (int j = ini; j <= fin; ++j) {
                if (v[j] == 0) {
                    cont++;
                }
            }
            cout << cont << endl;
        }
    }
}

int main() {
    int a, b;
    scanf("%d%d", &a, &b);

    vector<string> t;
    string tt;

    for (int i = 0; i <= b; i++) {
        getline(cin, tt);
        t.push_back(tt);
    }

    nn(a, t);

    return 0;
}