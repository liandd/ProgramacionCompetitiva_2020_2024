#include <bits/stdc++.h>
using namespace std;

long n;

void llenar(vector<long> &x){
    for(int i = 0; i < n; i++) cin>>x[i];
}

int main(){
    cin>>n;
    vector<long> a(n);
    vector<long> b(n);
    vector<long> c(n);

    llenar(a);
    llenar(b);
    llenar(c);


    for(int i = 0; i < n; i++){
        vector<long> aux(3);
        aux[0] = a[i];
        aux[1] = b[i];
        aux[2] = c[i];

        sort(aux.begin(), aux.end());

        cout<< aux[1] << (i == n - 1 ? "\n" : " ");
    }


    return 0;
}
