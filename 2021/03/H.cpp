#include <bits/stdc++.h>
using namespace std;

struct Persona{
    int valor;
    char letra;
};

bool cmp(Persona a, Persona b){
    return a.valor < b.valor;
}

int main(){
    int n, let = 65;
    cin>>n;

    vector<Persona> p;

    for(int i = 0; i < n; i ++){
        int aux;
        cin>>aux;
        for(int j = 0; j < aux; j++){
            Persona pers;
            pers.letra = (char) let;
            cin>>pers.valor;

            p.push_back(pers);
        }
        let++;
    }

    sort(p.begin(), p.end(), cmp);

    for(int i = 0; i < p.size(); i ++){
        cout<< ((char) p[i].letra);
    }

    cout<<"\n";

    return 0;
}
