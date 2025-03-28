#include<bits/stdc++.h>
using namespace std;
int R,C,K;
char grid[1000];
char grid2[1000];
bool ls() {
    bool apagado = false;
    bool prendido = false;
    int z=0;
    while(z<R){
        for (int i = 0; i < C; i++) {
            if (grid[i] == '-') {
                apagado = true;
            }
        }
        for (int j = 0; j < K; j++) {
            if (grid2[j] == '*') {
                prendido = true;
            }
        }
        if(apagado && prendido){
            return true;
        }
        z++;
        apagado = false;
        prendido = false;
    }
    return false;
}

int main(){
    cin>>R>>C>>K;
    cin.ignore();
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            cin >> grid[j];
        }
        for (int k = 0; k < K; k++) {
            cin >> grid2[k];
        }
    }
    if (ls()) {
        cout << "N\n";
    }else cout<<"Y\n";
    return 0;
}
