#include <bits/stdc++.h>
using namespace std;

int main(){
    vector<int> primos;
    vector <bool> isPrimo (400, true);
    isPrimo[0] = isPrimo[1] = false;
    for(int i = 2; i < 400; ++i){
        if(isPrimo[i]){
            primos.push_back(i);
            for(int  h = 2; h * i < 400; ++h){
                isPrimo[i * h] = 0;
            }
        }
    }

    int A;
    cin>>A;
    while(A--){
        int N, contador = 0;
        cin>>N;
        for(int i = 0; primos[i] < N; i++)
            for(int j = i; primos[j] <= (N - primos[i]); j++)
                if (primos[i] + primos[j] == N)
                    contador++;
        cout<<contador<<"\n";
    }
    return 0;
}
