#include <bits/stdc++.h>
using namespace std;

class persona{
    public:
    string nombre;
    int prioridad;

    persona(string n, int pr){
        nombre = n;
        prioridad = pr;
    }
};

bool operator<(const persona& a, const persona& b){
    return a.prioridad < b.prioridad;
}

int main(){
    priority_queue<persona> pq;
    string n;
    int p;

    while(cin>>n){
        if(n == "V"){
            if(!pq.empty()){
                persona pers = pq.top();
                pq.pop();
                cout<<pers.nombre<<"\n";
            }else{
                cout<<"\n";
            }
        }else{
            cin>>p;
            pq.push(persona(n, p));
        }
    }
    return 0;
}
