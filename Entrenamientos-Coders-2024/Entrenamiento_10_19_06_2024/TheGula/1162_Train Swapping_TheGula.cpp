#include <bits/stdc++.h>

using namespace std;

int movientos (vector <int>& v) {
    int x = v.size();
    int cont=0, aux;

    for (int i = 0; i <x; i++) {
        for(int j=0; j<x-1; j++) {
            if(v[j+1] < v[j]) {
            aux= v[j];
            v[j]=v[j+1];
            v[j+1]=aux;
            cont++;
            }

        }
    }

    return cont;
}

int main() {
    int n;
    int l;
    int x;
    vector<int> v;

    scanf("%d", &n);
    while(n--) {
        scanf("%d", &l);
        for(int i=0; i<l; i++) {
            scanf("%d", &x);
            v.push_back(x);
        }
        int res =movientos(v);
        cout<<"Optimal train swapping takes "<<res<<" swaps."<<"\n";
        v.clear();
    }

    return 0;
}