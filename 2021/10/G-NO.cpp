#include <bits/stdc++.h>
using namespace std;

bool solve(int inicio, vector<int> a, int dif){
    for(int i = inicio; i < 6; i++)
        if(dif - a[i] == 0) return true;
    return false;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int A;
    cin>>A;
    while(A--){
        int salida = 0;
        vector<int> a(6);
        for(int i = 0; i < 6; i++){
            cin>>a[i];
            salida += a[i];
        }
        if(salida % 2 == 0){
            int divisor = salida / 2;
            sort(a.rbegin(), a.rend());
            if(a[0] == divisor)
                cout<<"Tobby si puede cruzar\n";
            else if(a[0] > divisor)
                cout<<"Tobby no puede cruzar\n";
            else{
                bool ver = false;
                for(int i = 0; i < 5; i++){
                    divisor -= a[i];
                    if(solve(i + 1, a, divisor))
                        ver = true;
                }
                cout<< (ver ? "Tobby si puede cruzar\n" : "Tobby no puede cruzar\n");
            }
        }else
            cout<<"Tobby no puede cruzar\n";
    }
    return 0;
}
