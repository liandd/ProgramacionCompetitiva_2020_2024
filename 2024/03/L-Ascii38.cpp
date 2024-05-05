#include<bits/stdc++.h>
using namespace std;
int R,C,K;
char grid[1000];
char grid2[1000];
/*bool ls() {
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
*/
int main(){
    cin>>R>>C>>K;
    cin.ignore();
    bool prendido = false;
    bool apagado = false;
    bool resultado = false;
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            cin >> grid[j];
            if(grid[j] == '-'){
            	apagado = true;
			}
        }
        cin.get();
        for (int h = 0; h < K; h++) {
            cin >> grid2[h];
            if(grid2[h] == '*'){
            	prendido = true;
			}
        }
        cin.ignore();
        if(apagado && prendido){
        	resultado = true;
		}
		prendido = apagado = false;
    }
    (resultado) ? cout<<"N\n" : cout<<"Y\n";
    /*if (ls()) {
        cout << "N\n";
    }else cout<<"Y\n";*/
    return 0;
}
