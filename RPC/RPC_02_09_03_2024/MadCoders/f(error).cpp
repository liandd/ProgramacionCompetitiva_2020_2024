#include<bits/stdc++.h>
using namespace std;

int main() {
    int n, c, aux;
    cin >> n >> c;
    // vector<int> llegadas(n);
    int acumuladon=0;
    int resta=0;
    for(int i = 0; i < n; i++) {
        cin >> aux;
        if(i==0){
            if(n==aux && c == 1){
                cout<<"imposible";
                break;
            }
        }
        // cin >> llegadas[i];

        resta= aux+acumuladon;
        resta=resta-c;
        acumuladon=resta;
        // cout<<resta<<endl;
            // cout<<i;
        if(resta ==0){
            // cout<<i;
            cout<< n-(i+1);
        }

    }


    return 0;
}