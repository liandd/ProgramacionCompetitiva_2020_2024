#include <bits/stdc++.h>
using namespace std;
/*
2
3
portugues
chines
portugues
2
espanhol
espanhol
*/
int main() {
    int n, k;
    string s, ant;

    cin >> n;
    while (n--) {
        cin >> k;
        bool b = false;
        for (int i = 0; i < k; i++) {
            cin >> s;
            if (i == 0) {
                ant = s;
            } else {
                if (ant != s) {
                    b = true;
                }
            }
        }
        if(b==true){
            cout <<"ingles"<<"\n";
        }else{
            cout<<s<<"\n";
        }
    }

    return 0;
}
