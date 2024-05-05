#include <bits/stdc++.h>
using namespace std;

struct perro{
    string nombre;
    int cant;
};

bool cmp(perro a, perro b){
    return a.cant > b.cant;
}

bool cmp2(string a, string b){
    return a < b;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int T;
    cin>>T;
    vector<perro> aux(T);
    for(int i = 0; i < T; i++)
        cin>>aux[i].nombre>>aux[i].cant;
    sort(aux.begin(), aux.end(), cmp);
    vector<string> ord;
    ord.push_back(aux[0].nombre);
    ord.push_back(aux[1].nombre);
    ord.push_back(aux[2].nombre);

    sort(ord.begin(), ord.end(), cmp2);
    cout<<ord[0]<<" "<<ord[1]<<" "<<ord[2]<<" "<< (aux[0].cant * aux[1].cant * aux[2].cant )<<"\n";
    return 0;
}
