#include <bits/stdc++.h>

using namespace std;

int main() {
    string a;
    cin>>a;
    string horas = a.substr(0, 2), minutos = a.substr(3, 2);
    int tiempoHoras, tiempoMinutos;
    tiempoHoras = horas[0] - '0';
    tiempoMinutos = minutos[0] - '0';
    tiempoHoras *= 10;
    tiempoMinutos *= 10;
    tiempoHoras += (horas[1] - '0');
    tiempoMinutos += (minutos[1] - '0');
    int segundosHoras = (3600 * tiempoHoras + 60 * tiempoMinutos), segundosMinutos = (60 * tiempoHoras + tiempoMinutos);
    int total = segundosHoras - segundosMinutos;
    int horasTotal, minutosTotal, segundosTotal;
    segundosTotal = total % 60;
    total -= segundosTotal;
    total /= 60;
    minutosTotal = total % 60;
    total -= minutosTotal;
    horasTotal = total / 60;
    if(horasTotal < 10){
        cout<<"0"<<horasTotal<<":";
    } else {
        cout<<horasTotal<<":";
    }
    if (minutosTotal < 10) {
        cout<<"0"<<minutosTotal<<":";
    } else {
        cout<<minutosTotal<<":";
    }
    if (segundosTotal < 10) {
        cout<<"0"<<segundosTotal<<endl;
    } else {
        cout<<segundosTotal<<endl;
    }
    return 0;
}
