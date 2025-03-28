#include <bits/stdc++.h>

using namespace std;

int main() {
    int c;
    cin >> c;

    while (c--) {
        int p;
        cin >> p;

        map<char, int> g;

        for (int i = 0; i < p; i++) {
            char mrc, rbo;
            cin >> mrc >> rbo;

            g[mrc]++;
        }

        int mx = 0;
        char gdr = '-';
        bool empate = false;
        bool triempate = false;

        for (const auto& i : g) {
            if (i.second > mx) {
                mx = i.second;
                gdr = i.first;
                empate = false;
                triempate = false;
            } else if (i.second == mx) {
                if (mx == p / 3) {
                    triempate = true;
                } else {
                    empate = true;
                }
            }
        }

        if (triempate) {
            cout << "trempate\n";
        } else if (empate) {
            cout << "empate\n";
        }else{
            switch(gdr){
                case 'G':
                    cout<<"green\n";
                    break;
                case 'R':
                    cout<<"red\n";
                    break;
                case 'B':
                    cout<<"blue\n";
                    break;
            }
        }
    }

    return 0;
}